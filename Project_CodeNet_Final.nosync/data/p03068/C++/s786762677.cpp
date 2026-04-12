
#include<iostream>
#include<string>
using namespace std;

void komekome(int N,string &S,int K){
    char a = S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]!=a){
          S[i]='*';
        }
    }
}
int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    komekome(N,S,K);
    cout << S << endl;
    return 0;
}