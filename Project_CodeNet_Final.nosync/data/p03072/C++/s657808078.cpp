#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans=1;
    int now=h[0];
    rep2(i,1,n){
        if(now<=h[i]) ans++;
        now = max(now,h[i]);
    }
    cout << ans << endl;
    return 0;
}