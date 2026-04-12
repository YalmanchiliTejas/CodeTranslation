#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    int N;
    cin >> N;
    char S[N+1], c;
    int K;
    scanf("%s", S);
    cin >> K;
    c = S[K-1];
    for(int i = 0; i < N;i++){
        if(S[i] == c) cout << c;
        else cout << '*';
    }
    cout << endl;
    return 0;
}