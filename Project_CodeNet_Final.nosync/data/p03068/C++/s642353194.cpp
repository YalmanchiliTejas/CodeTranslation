#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    char s = S.at(K-1);
    for(int i = 0;i< N;i++){
        if(S.at(i) != s){
            S.at(i) = '*';
        }
    }
    cout << S << endl;
    return 0;
}