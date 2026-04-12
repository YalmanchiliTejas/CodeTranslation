
#include<iostream>
#include<string>
using namespace std;

string komekome(int N,string S,int K){
    //cout << &S << endl;
    char a = S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]!=a){
          S[i]='*';
        }
    }
    return S;
}
int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    //cout << &S << endl;
    cout << komekome(N,S,K) << endl;
    return 0;
}