#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){

    int N,K;
    string S;

    cin >> N >> S >> K;

    char tmp = S[K-1];

    for(int i=0;i<N;i++){
        if(S[i]!=tmp){
            S[i] = '*';
        }
    }

    cout << S << endl;


    return 0;
}