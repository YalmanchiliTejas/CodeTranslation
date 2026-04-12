#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;

int main(void){
    cin >> n >> k;
    lli ans = 0;
    for(lli b = k+1; b <= n; b++){
        ans+=n/b*(b-k) + max(0LL, n%b-k+1);
        if(k == 0) ans--;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
