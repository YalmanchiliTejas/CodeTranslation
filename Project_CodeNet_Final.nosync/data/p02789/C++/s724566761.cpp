//****** @mdazmat9 **********
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define EB emplace_back
#define endl "\n"
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int fast_pow(int x, int y, int p);
char diff(char a,char b){
    for(char x='a';x<='z';x++){
        if(x!=a && x!=b)return x;
    }
}
void solve() {
    int n,m;cin>>n>>m;
    if(n==m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int32_t main() {
    IOS;
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
int fast_pow(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}