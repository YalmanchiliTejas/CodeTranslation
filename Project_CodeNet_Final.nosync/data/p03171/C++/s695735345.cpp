//****** @mdazmat9 **********
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define MOD2 1000000007
#define MOD 998244353
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
typedef pair<int, int> pr;
typedef vector<int> VI;
typedef vector<pr> VP;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace(v) for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
int fast_pow(int x, int y, int p);
const int MAX_SIZE = 200001;
int n;VI a;
int dp[3001][3001];
int rec(int i,int j,int cnt){
    if(i>j)return 0;
    int& ans=dp[i][j];
    if(ans!=-1)return ans;
    int op1=a[i]-rec(i+1,j,!cnt);
    int op2=a[j]-rec(i,j-1,!cnt);
    ans=max(op1,op2);
    return ans;
}
void solve() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.EB(x);
    }
    memset(dp,-1, sizeof(dp));
    cout<<rec(0,n-1,1);
}

int32_t main() {
    IOS;
    int test = 1;
//    cin >> test;
    for(int i=1;i<=test;i++){
//        cout<<"Case #"<<i<<": ";
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