#include <iostream>
using namespace std;
int main(void){
    
    //変数：店舗 A の売上個数「s1 と s2」と置く
    int s1, s2;
    
    while(cin >> s1 >> s2){

        //条件：店舗 A の売上個数「s1 と s2」が「 0 と 0 」のとき break する
        if(s1 == 0 && s2 == 0) break;
        
        //代入：最大売上個数を「 max = s1 + s2 」と最大売上店舗「 store = 'A' 」と代入して置く
        int max = s1 + s2;
        char store = 'A';
        
        //繰返し：店舗 B ～  店舗 E の売上個数「s1 と s2」を入力するための繰返し
        for(int i = 1; i <= 4; i++){
            cin >> s1 >> s2;
            
            //条件：最大売上個数を求めるために比較する  ➡   最大個数を入れ替え  ＋   店舗に１加えBCDEへと変化させていく
            if(max < s1 + s2) max = s1 + s2, store = 'A' + i;
        }
        
        cout << store << " " << max << endl;
    }
}

