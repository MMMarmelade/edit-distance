void op_print(edis_info* sol) {
	int** ed=sol->d, ** B=sol->B;
	int i = sol->m-1;
	int j = sol->n-1;
	while (i >= 0 && j >= 0) {
		switch (B[i][j]) {
		case LEFT:
			cout << B[i][j] << "insert" << i << j << "<--";
			--j;
			break;
		case UPPER:
			cout << B[i][j] << "delete" << i << j << "<--";
			--i;
			break;
		case LANDU:
			if (ed[i - 1][j - 1] == ed[i][j])
				cout << B[i][j] << "copy" << i << j << "<--";
			else
				cout << B[i][j] << "replace" << i << j << "<--";
			--i;
			--j;
			break;
		default:
			return;
		}
	}
}
