using namespace std;
#include<iostream>

const int LEFT = 1;
const int UPPER = 2;
const int LANDU = 3;

//
struct edis_info {
	int** d;//edit distance table
	int** B;//label of dividing subproblem
};

/*
input: sequence S1 and sequence S2
output: edit distance and sequence of operations
*/
edis_info* edistance(string S1, string S2) {
	string tS1 = '0' + S1;//S1[0] and S2[0] means the 0-length situation
	string tS2 = '0' + S2;
	int m = tS1.length();
	int n = tS2.length();
	//m*n table: edit distance
	int** edis = (int**)malloc(sizeof(int*) * m);
	for (int i = 0;i < m;i++)
		edis[i] = (int*)malloc(sizeof(int) * n);

	int** B = (int**)malloc(sizeof(int*) * m);
	for (int i = 0;i < m;i++)
		B[i] = (int*)malloc(sizeof(int) * n);
	//initial
	for (int i = 0;i < m;i++) {
		edis[i][0] = i;
		B[i][0] = 0;
	}
	for (int j = 0;j < n;j++) {
		edis[0][j] = j;
		B[0][j] = 0;
	}

	for(int i=1;i<m;i++)
		for (int j = 1;j < n;j++) {
			//temp-values for each operations
			int eddel = edis[i - 1][j]+1;//delete
			int edins = edis[i][j - 1] + 1;//insert
			int edrep = edis[i - 1][j - 1];//replace, actually here contains the copy operation.
			if (tS1[i] != tS2[j])//the replace temp-value increses 1 when the two letters are different
				edrep++;
			if (eddel <= edins && eddel <= edrep) {
				edis[i][j] = eddel;
				B[i][j] = UPPER;
			}
			else if (edins <= eddel && edins <= edrep) {
				edis[i][j] = edins;
				B[i][j] = LEFT;
			}
			else if (edrep <= eddel && edrep <= edins) {
				edis[i][j] = edrep;
				B[i][j] = LANDU;
			}
		}

	edis_info* edis_sol = new edis_info;
	edis_sol->d = edis;
	edis_sol->B = B;
	return edis_sol;
}


int main() {
	string S1 = "akdndd";
	string S2 = "sdndsd";
	edis_info* sol=edistance(S1, S2);
	int m = S1.length()+1;
	int n = S2.length()+1;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cout << sol->d[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cout << sol->B[i][j] << "    ";
		}
		cout << endl;
	}
}
