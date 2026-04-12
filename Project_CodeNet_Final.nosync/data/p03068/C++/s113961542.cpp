#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K; string S; cin >> N >> S >> K; --K;
    for (int i=0;i<N;++i) if (S[i]!=S[K]) S[i]='*';
    cout << S << '\n';
}