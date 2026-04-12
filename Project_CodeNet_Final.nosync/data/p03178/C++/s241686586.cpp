#include<bits/stdc++.h>
typedef long long ll;
typedef double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 2e5+100;
const ll bits = 21;
const ll mod = 1e9+7;
const ld pi = 3.14159265358979323846;


int main(){
    FASTIO;
    PRECISION;

    string s;
    cin>>s;
    ll d;

    cin>>d;

    vector< vector<ll> >dp(d,vector<ll>(2));
    dp[0][1] = 1;

    for(int i=0;i<s.size();i++){
        vector< vector<ll> >ndp(d,vector<ll>(2));
        for(int sum=0;sum<d;sum++){
            for(int t=0;t<2;t++){
                int up = 9;
                if(t){
                    up = s[i]-'0';
                }
                for(int x=0;x<up;x++){
                    ndp[(sum+x)%d][0]+=dp[sum][t];
                    ndp[(sum+x)%d][0]%=mod;
                    
                }
                ndp[(sum+up)%d][t]+=dp[sum][t];
                ndp[(sum+up)%d][t]%=mod;
            }
        }

        // for(int i=0;i<d;i++){
        //     cout<<ndp[i][0]<<" "<<ndp[i][1]<<", ";
        // }
        // cout<<"\n";

        dp = ndp;
    }

    cout<<(dp[0][1]+dp[0][0]-1+mod)%mod<<"\n";
}