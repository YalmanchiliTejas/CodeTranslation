/*
    2014.06.27
    C language Lecture week ∞
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Width_Max 100
#define Height_Max 1000
#define Taken_Max 65536
#define Cmd_Length_Max 8

// データ構造としては　縦 num_height * 横 num_width のマスに文字の書かれた立方体を入れていくイメージ
// 箱の記憶域
int matrix[Width_Max][Height_Max];
// 山の高さの記憶
int height[Width_Max];

// コマンド文字列定義
// とりあえず今はコマンド4個
char cmdstr[][Cmd_Length_Max] = { "push", "pop", "move", "quit" };
int cmd_max = 4;

// 命令を処理する関数定義
void cmd_0_push ( int p1, char s1 );
void cmd_1_pop ( int p1 );
void cmd_2_move ( int p1, int p2 );


// やっとメイン
int main (void) {
    
    // 初期化
    for ( int lw = 0; lw < Width_Max; lw ++ ) {
        height[lw] = 0;
    }
    
    // コード類
    int qcode = 0;      // Quit (1) or not (0)
    
    int tmp;
    
    // 山の数の入力を得る...?（いらなくね？）
    scanf ( "%d", &tmp );
    
    // どうせ間違ったコマンドが入力されないなら実は三文字目で識別可能
    // これで高速化を狙う？（対応性は下がるのでやらないことにする）
    
    char input_cmd[Cmd_Length_Max];      // 入力されたコマンド文字列がここに入る
    
    int input_p1;
    int input_p2;
    char input_s1;
    
    int cmd_code;
    
    while(1){
        
        scanf ( "%s", input_cmd );
        
        cmd_code = -1;
        for ( int cnt = 0; cnt < cmd_max; cnt ++ ){
            if ( strcmp( input_cmd, cmdstr[cnt] ) == 0 ){
                cmd_code = cnt;
                break;
            }
        }
        
        switch ( cmd_code ) {
        case 0 :        // command PUSH
            scanf ( "%d %c", &input_p1, &input_s1 );
            cmd_0_push ( input_p1, input_s1 );
            break;
        case 1 :        // command POP
            scanf ( "%d", &input_p1 );
            cmd_1_pop ( input_p1 );
            break;
        case 2 :        // command MOVE
            scanf ( "%d %d", &input_p1, &input_p2 );
            cmd_2_move ( input_p1 , input_p2 );
            break;
        case 3 :        // command QUIT
            qcode = 1;
            break;
        default :        // command None
            printf ( "Wrong command inputted!\n" );
            break;
        }
        
        if ( qcode == 1 ) {
            break;
        }
        
    }
    
    return 0;
    
}

void cmd_0_push ( int p1, char s1 ){
    matrix[p1][height[p1]] = s1;
    height[p1] ++;
    return;
}

void cmd_1_pop ( int p1 ){
    height[p1] --;
    printf ( "%c\n", matrix[p1][height[p1]] );
    return;
}

void cmd_2_move ( int p1, int p2 ){
    height[p2] ++;
    matrix[p2][height[p2]-1] = matrix[p1][height[p1]-1];
    height[p1] --;
    return;
}

// EOF