#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

int cell[MAX][MAX];

int main()
{
    int row, col;

    scanf("%d %d", &row, &col);

    for(int i = 0; i < row; i++){
        char str[105];
        scanf("%s", str);
        for(int j = 0; j < col; j++){
            if(str[j] == '.')
                cell[i][j] = 0;
            else if(str[j] == '#')
                cell[i][j] = 1;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(cell[i][j] == 0){
                int flag1 = 1, flag2 = 1;
                for(int k = 0; k < row; k++){
                    if(cell[k][j] == 1){
                        flag1 = 0;
                        break;
                    }
                }
                if(flag1){
                    for(int k = 0; k < row; k++){
                        cell[k][j] = -1;
                    }
                }
                for(int k = 0; k < col; k++){
                    if(cell[i][k] == 1){
                        flag2 = 0;
                        break;
                    }
                }
                if(flag2){
                    for(int k = 0; k < col; k++){
                        cell[i][k] = -1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < row; i++){
        int cnt = 0;
        for(int j = 0; j < col; j++){
            if(cell[i][j] == 0)
                printf("."), cnt++;
            else if(cell[i][j] == 1)
                printf("#"), cnt++;
        }
        if(cnt)
            printf("\n");
    }

    //printf("\n");

    return 0;
}
