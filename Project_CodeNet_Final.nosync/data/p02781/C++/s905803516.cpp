#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll choose(int n, int k){
    ll x=1;
    ll y=1;
    rep(i, k){
        x*=(n-i);
        y*=i+1;
    }
    return x/y;
}
int main(void){
    string s;
    int k;
    cin>>s;
    cin>>k;
    int digit=s.size();
    ll ans;
    if(digit-1<k) ans=0;
    else ans=choose(digit-1, k)*pow(9, k);
    //cout<<ans<<endl;
    vector<vector<int> > dp1(digit+1, vector<int>(10));
    vector<vector<int> > dp2(digit+1, vector<int>(10));
    dp1[0][0]=0;
    dp1[0][1]=(s[0]-'0')-1;
    dp2[0][1]=1;
    int dp2now=1;
    for(int i=1;i<=digit-1;i++){
        rep(j, 4){
            if(j==0){
                dp1[i][j]=dp1[i-1][j]+dp2[i-1][j]*min((s[i]-'0'), 1);
            }
            else dp1[i][j]=dp1[i-1][j-1]*9+dp1[i-1][j]+dp2[i-1][j-1]*max((s[i]-'0'-1), 0)+dp2[i-1][j]*min((s[i]-'0'), 1);
        }
        if(s[i]=='0'){
            if(dp2now>=4) continue;
            dp2[i][dp2now]=1;
        }
        else {
            if(dp2now+1>=4) {
                dp2now=10;
                continue;
            }
            dp2now++;
            dp2[i][dp2now]=1;

        }
    }
    ans+=dp1[digit-1][k]+dp2[digit-1][k];
    cout<<ans<<endl;
    return 0;
}