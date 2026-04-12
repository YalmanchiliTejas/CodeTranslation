#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
int N,K;
string S;
int main(){
    cin >> N >> S >> K;
    rep(i,N) if(S[i] != S[K-1]) S[i] = '*';
    cout << S << endl;
}