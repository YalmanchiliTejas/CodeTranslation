#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf 1000000000
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define yoi cout<<"yo"<<endl;
#define debug(i) cout<<i<<endl;
const int mod=1e9 +7;
int main(){
IOS;
string k;
lli d,i,j,l;
cin>>k;
cin>>d;
lli dp[k.length()+1][d][2];
memset(dp,0,sizeof(dp));
dp[0][0][0]=1;
for(i=1;i<=k.length();i++){
    for(j=0;j<d;j++){
            for(bool small:{false,true}){
        for(l=0;l<=9;l++){
                if(!small&&k[i-1]-48<l)
                break;
                int x=j-l;
                while(x<0)
                    x+=d;
                dp[i][j][small||l<k[i-1]-'0']=(dp[i][j][small||l<k[i-1]-'0']+dp[i-1][x][small])%mod;
                //dp[i][(j+l)%d][small||l<k[i-1]-'0']=dp[i-1][j][small]+dp[i][(j+l)%d][small||l<k[i-1]-'0'];
        }
        }
    }
}
lli ans=(dp[k.length()][0][false]+dp[k.length()][0][true])%mod;
ans--;
if(ans<0)
    ans+=mod;
cout<<ans<<endl;
}
