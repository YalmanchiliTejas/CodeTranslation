#include <stdio.h>
#include <ctype.h>

typedef long long ll;

ll H,W;
int board[100][100];
int main(){
        scanf("%lld %lld",&H,&W);
        for(int y = 0; y < H; y++){
                for(int x = 0; x < W; x++){
                        char c;
                        do{scanf("%c",&c);}while(isspace(c));
                        board[x][y]=c;
                }
        }

        for(int y = 0; y < H ; y++){
                int found = 0;
                for(int x = 0; x < W; x++){
                        if(board[x][y] == '#'){ found = 1; break;}
                }
                if(found == 0){
                        for(int x = 0; x < W; x++) board[x][y] = '*';
                }
        }
        for(int x = 0; x < W ; x++){
                int found = 0;
                for(int y = 0; y < H; y++){
                        if(board[x][y] == '#'){ found = 1; break;}
                }
                if(found == 0){
                        for(int y = 0; y < H; y++) board[x][y] = '*';
                }
        }

        for(int y = 0; y < H; y++){
                char needNewLine = 0;
                for(int x = 0; x < W; x++){
                        if(board[x][y] != '*'){
                                needNewLine = 1;
                                printf("%c",board[x][y]);
                        }
                }
                if(needNewLine) puts("");
        }
}