#include <bits/stdc++.h>

using namespace std;

int rowid[100], colid[100];

int main(){
    int row, col, i, j, flag=0;
    scanf("%d %d ", &row, &col);
    char mat[row][col+1];
    for(i=0; i<row; i++){
        for(j=0; j<col; j++) scanf("%c", &mat[i][j]);
        cin.ignore();
    }
    /*for(i=0; i<row; i++){
        for(j=0; j<col; j++) printf("%c", mat[i][j]);
        printf("\n");
        //getchar();
    }*/
    for(i=0; i<row; i++){
        flag=0;
        for(j=0; j<col; j++){
            if(mat[i][j]=='#'){
                flag=1;
                break;
            }
        }
        if(!flag&1) rowid[i]=1;
    }
    for(i=0; i<col; i++){
        flag=0;
        for(j=0; j<row; j++){
            if(mat[j][i]=='#'){
                flag=1;
                break;
            }
        }
        if(!flag&1) colid[i]=1;
    }
    for(i=0; i<row; i++){
        if(!rowid[i]&1){
            for(j=0; j<col; j++){
                if(!colid[j]&1) printf("%c", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
