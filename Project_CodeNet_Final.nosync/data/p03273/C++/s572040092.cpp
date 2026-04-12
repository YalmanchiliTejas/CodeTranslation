#include <iostream>
#include <string>
using namespace std;


int main(){

    int H, W;
    string a[100];
    cin >> H >> W;
    for( int i = 0; i < H; i++ ){
        cin >> a[i]; 
    }


    string white_line;
    for( int i = 0; i < W; i++ ) white_line += ".";
    
    string del_line[100];
    int line = 0, col = W;

    // 行の白マスを消去
    for( int i = 0; i < H; i++ ){
        if( a[i] != white_line ){
            del_line[line] = a[i];
            line++;
        }
    }

    // 列の白マスを削除
    for( int i = 0; i < col; i++ ){
        bool del = true;
        for( int j = 0; j < line; j++ ){
            if(del_line[j][i] == '#' ){
                del = false;
                break;
            }
        }
        if( del ){
            for( int j = 0; j < line; j++ ){
                del_line[j].erase( del_line[j].begin() + i );
            }
            col--;
            i--;
        }
    }
    
    // 表示
    for( int i = 0; i < line; i++ ) cout << del_line[i] << endl;

    return 0;

}