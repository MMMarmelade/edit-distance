# edit-distance
to computing the shortest edit-distance of two string

Edit-distance: to transform S1 to S2, we need a serial of operations, for example, delete, insert, replace, copy..., the number of the operations is the edit-distance.

Input: string S1 and S2.

m=S1.length();
n=S2.length();

The editing operations are devided into 3 types: insert, delete, replace. 

By dynamic programming, we have subproblem: S1[1...i] and S2[1...j], the boundary is [i,j]

Insert: inserting S1[i] after S2[j], and then we have the subproblem of [i,j-1]. Meanwhile, the edit-distance need to +1(ed[i][j]=ed[i][j-1]+1);

Delete: deleting S1[i], and then we have the subproblem of [i-1,j]. Meanwhile, the edit-distance need to +1(ed[i][j]=ed[i-1][j]+1);

Replace: replacing S1[i] with S2[j], and then we have the subpromblem of [i-1,j-1]. And the copy operation yields the same subproblem, therefore, the two situations are merged. If S1[i]!=S2[j], the edit-distance need to +1(ed[i][j]=ed[i-1][j-1]+1); otherwise, ed[i][j]=ed[i-1][j-1].

*above upgraded at 22/1/2020
