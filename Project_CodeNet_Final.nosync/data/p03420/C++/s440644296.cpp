#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n,k;cin >> n >> k;
    ll ans = 0;
    for(int b = 1;b <= n;b++){
        int m = n/b;
        int r = n%b;
        ans += m*max(b-k,0) + max(0,r-k+1);
        if(k==0) ans--;
    }
    cout << ans << endl;
}