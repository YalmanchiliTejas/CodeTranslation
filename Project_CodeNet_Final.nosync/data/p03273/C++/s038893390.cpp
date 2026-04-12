#include <bits/stdc++.h>
using namespace std;
//ここまでで習っていないので、配列の値の削除pop_back()は使用しないで解くこととする
int main() {
	int H , W;
  	cin >> H >> W;
    //列と行のそれぞれの数値を読み込む
  	vector<vector<char>> hyo(H, vector<char>(W));
  	for(int i = 0; i < H; i++){
    	for(int j = 0; j < W; j++){
        	cin >> hyo.at(i).at(j);
        }
    }
    //列がすべて'.'の数を数えるためにcount変数を用意する
    int count = 0;
    for(int i = 0; i < W; i++){
        //列がすべて'.'かどうかを調べるためにtate_check変数を用意する
      	bool tate_check = true;
        //各行のi - count 列目がすべて'.'がかどうかを調べる  
        for(int j = 0; j < H; j++){
            //もしi - count列目で'.'ではない値があればtate_checkをfalseにしてループを抜ける
           	if(hyo.at(j).at(i - count) != '.'){
               	tate_check = false;
               	break;
            }
        }
        // i - count列目がすべて'.'だったらtate_check == trueなので
        // i - count列目以降の右側の値をひとつずつ左にずらしていく
        if(tate_check == true){
            for(int k = 0; k < H; k++){
               	for(int l = i - count; l < W - 1; l++){
                    hyo.at(k).at(l) = hyo.at(k).at(l + 1);
                }
            }
            //count変数を1増やす
            count++;
        }
    }
  	for(int i = 0; i < H; i++){
        //行がすべて'.'かどうかを調べるためにyoko_check変数を用意する
        bool yoko_check = true;
    	for(int j = 0; j < W ; j++){
            //もしi行目で'.'ではない値があればyoko_checkをfalseにしてループを抜ける
        	if(hyo.at(i).at(j) != '.'){
              	yoko_check = false;
            	break;
            }
        }
        //もしi行目のyoko_check変数がfalseだったらi行目をw - count列まで出力する
        //つまり列がすべて'.'だったcount列分の右側は出力しないし
        //yoko_check変数がtrueだったらそもそもi行目自体出力しない
      	if(yoko_check == false){
        	for(int j = 0 ; j < W - count; j++){
            	cout << hyo.at(i).at(j);
            }
            //次の行の出力に向けて改行する
          	cout << endl;
        }
    }
}