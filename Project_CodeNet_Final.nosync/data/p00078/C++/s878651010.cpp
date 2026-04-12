#include <bits/stdc++.h>
#define MAX_N 15
#define INF -1
using namespace std;
int n;
int board[MAX_N][MAX_N];

void create() {
    int y = n/2, x = y;
    y++;
    int num = 1;
    //中央に１を入れる
    board[y][x] = num++;
    while(num <= n*n) {
        y++;x++; //右斜め下へ移動
        do {
            if(x >= n) { //右にはみ出した
                x = 0;//左端へ
            } else if(y >= n) { //下にはみ出した
                y = 0;//上へ
            } else if(x < 0) { //左にはみ出した
                x = n-1;//右端へ
            } else if(board[y][x] != INF) { //すでに数字が入っていた
                y++;x--;//左斜め下へ
            }
            //cout << "do-while roop" << endl;
        }while((x<0||x>=n||y<0||y>=n)||(board[y][x]!=INF));
        board[y][x] = num++;
    }
}

void print() {
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            printf("%4d", board[r][c]);
            if(c == n - 1) putchar('\n');
        }
    }
}

int main(void) {
    while(cin >> n, n != 0) {
        memset(board, INF, sizeof(board));
        create();
        print();
    }
    return(0);
}