#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    // あとで消す
    //std::ifstream in("ein4.txt");
    //std::cin.rdbuf(in.rdbuf());

    string N;
    int K;

    cin >> N >> K;

    // 桁DPをやっていく
    // [桁インデックス i][以下フラグ j][状態 s] 
    // 0<= ID <|N|
    // j \in {0,1} 0:未確定 1:確定
    // s \in {0個, 1個, 2個, 3個} 4以上は消える

    int lenN = N.length();
    int numS = 4;


    // 各桁の数字を数値として保持
    vector<int> lstr(lenN);
    for(size_t i=0;i<lenN;i++) lstr.at(i) = N.at(i)-48;

    // DP用のテーブル
    vector< vector< vector<long long> > > DP(lenN, vector< vector<long long> >(2, vector<long long>(numS,0)));

    // 初期化
    DP.at(0).at(0).at(1) = 1;                   // 数字が同じなのは未確定   N
    DP.at(0).at(1).at(1) = lstr.at(0)-1;        // 数字が小さいのは確定     1,...,N-1
    DP.at(0).at(1).at(0) = 1;                   // 先頭が0なのは確定        0

    for(size_t i=1;i<lenN;i++){
        if(lstr.at(i)==0){
            DP.at(i).at(1).at(0) = DP.at(i-1).at(1).at(0);
            DP.at(i).at(1).at(1) = DP.at(i-1).at(1).at(1) + DP.at(i-1).at(1).at(0)*9;
            DP.at(i).at(1).at(2) = DP.at(i-1).at(1).at(2) + DP.at(i-1).at(1).at(1)*9;
            DP.at(i).at(1).at(3) = DP.at(i-1).at(1).at(3) + DP.at(i-1).at(1).at(2)*9;
            DP.at(i).at(0).at(0) = DP.at(i-1).at(0).at(0);
            DP.at(i).at(0).at(1) = DP.at(i-1).at(0).at(1);
            DP.at(i).at(0).at(2) = DP.at(i-1).at(0).at(2);
            DP.at(i).at(0).at(2) = DP.at(i-1).at(0).at(2);
        }else{
            DP.at(i).at(1).at(0) = DP.at(i-1).at(1).at(0) + DP.at(i-1).at(0).at(0);
            DP.at(i).at(1).at(1) = DP.at(i-1).at(1).at(1) + DP.at(i-1).at(1).at(0)*9 + DP.at(i-1).at(0).at(0)*(lstr.at(i)-1) + DP.at(i-1).at(0).at(1);
            DP.at(i).at(1).at(2) = DP.at(i-1).at(1).at(2) + DP.at(i-1).at(1).at(1)*9 + DP.at(i-1).at(0).at(1)*(lstr.at(i)-1) + DP.at(i-1).at(0).at(2);
            DP.at(i).at(1).at(3) = DP.at(i-1).at(1).at(3) + DP.at(i-1).at(1).at(2)*9 + DP.at(i-1).at(0).at(2)*(lstr.at(i)-1) + DP.at(i-1).at(0).at(3);
            DP.at(i).at(0).at(0) = 0;
            DP.at(i).at(0).at(1) = DP.at(i-1).at(0).at(0);
            DP.at(i).at(0).at(2) = DP.at(i-1).at(0).at(1);
            DP.at(i).at(0).at(3) = DP.at(i-1).at(0).at(2);
        }
    }

    cout << DP.at(lenN-1).at(1).at(K)+DP.at(lenN-1).at(0).at(K) << endl;


    return 0;
}
