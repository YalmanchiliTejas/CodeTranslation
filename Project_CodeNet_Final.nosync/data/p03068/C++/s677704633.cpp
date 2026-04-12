#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    for(int i=0;i<N;i++){
        if(S[i]==S[K-1]) continue;
        S[i] = '*';
    }
    cout<<S<<endl;
    return 0;
}