#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){

    //入力
    int N, K;
    cin >> N;

    string S;
    cin >> S;

    cin >> K;

    //処理
    int i = 0;
    while(S[i] != '\0'){
        if(S[i] != S[K-1])   S[i] = '*';
        i++;
    }

    //出力
    cout << S << endl;

}