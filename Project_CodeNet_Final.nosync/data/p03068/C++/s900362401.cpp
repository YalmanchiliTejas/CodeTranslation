#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,K;
    string S;
    cin >> N >> S >> K;
    int tar = S[K-1];
    for(auto &c:S){
        if(c != tar)c = '*';
    }
    cout << S << endl;
}