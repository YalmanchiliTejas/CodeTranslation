#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll d;
    string s;
    cin>>s>>d;
    ll n=s.length();
    ll dp[n+1][2][d+1];
    ll num;
    
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            num=j?9:(s[i]-'0');
            for(int k=0;k<=num;k++){
                for(int x=0;x<d;x++){
                    dp[i+1][j|(k<num)][(k+x)%d]+=dp[i][j][x]%=mod;
                }
            }
        }
    }
    cout << (dp[n][0][0]+dp[n][1][0]+mod-1)%mod <<endl;
    return 0;

}
