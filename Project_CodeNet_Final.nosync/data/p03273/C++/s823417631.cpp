#include<iostream>
using namespace std;
bool use[2][100];//グローバル変数のboolは自動的にfalseで初期化される
int main()
{
    
    int h, w;
    cin >> h >> w;
    char c[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
            if(c[i][j] == '#'){
                //一つでも黒のある行、列は使用する可能性があるのでtrueとする
                use[0][i] = true;//行に関するbool
                use[1][j] = true;//列に関するbool
            }
        }
    }
    for(int i = 0; i < h; i++)if(use[0][i]){
        //全部白の行ではfalseなので繰り返し処理が飛ばされる
        //if(use[0][i]) ここにifでもいい
        for(int j = 0; j < w; j++)if(use[1][j]){
            //全部白の列では繰り返し処理が飛ばされる
            cout << c[i][j];
        }
        cout << endl;
        //文字の存在する行だけendlが出力
    }
    return 0;
}
