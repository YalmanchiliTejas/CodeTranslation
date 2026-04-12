#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    char Judge = S[K-1];
    for(int i = 0; i < N; i++)
    {
        if(S[i] != Judge) S[i] = '*';
    }
    cout << S << endl;
}