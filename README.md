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

In the test, S1 = "akdndd", S2 = "sdndsd".

Here is the test consequence:

![above is the edit-distances table, below is the subproblem directions table, 1 means left, 2 means upper, 3 means left and upper.](https://github.com/MMMarmelade/edit-distance/blob/master/2020-01-23_edit_distance.png)

above is the edit-distances table, below is the subproblem directions table, 1 means left, 2 means upper, 3 means left and upper.

And left corresponding to insert, upper corresponding to delete, left and upper corresponding to replace or copy

ed[6][6] equals to 3, that means S1 transform to S2 need 3 editing operations at least.

The below table named B[][]. Starting from the B[6][6], we get a 3(left and up), thus the next step is B[5][5]; and here we get a 1(left), so the next one is B[5][4], and so on. Eventually, we will get the sequence of operations, that is "replace, delete, copy, copy, copy, insert, copy". "Replace, delete, insert" need extra operation, therefore, the total operation cost is 3, which equals to ed[6][6].

*above upgraded at 22/1/2020
