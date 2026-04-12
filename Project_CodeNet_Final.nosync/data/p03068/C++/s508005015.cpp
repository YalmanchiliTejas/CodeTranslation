#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,K;
    string S;
    char lowercase;

    cin >> N;
    cin >> S;
    cin >> K;

    lowercase = S[K-1];

    for(int i=0;i<N;i++){
        if(S[i]!=lowercase){
            S[i] = '*';
        }
    }
    cout << S << endl;

    return 0;
}