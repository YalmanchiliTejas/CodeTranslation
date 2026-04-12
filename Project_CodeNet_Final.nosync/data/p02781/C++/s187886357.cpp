#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end() 

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
ll dp[2][105][5];



int main(){
    string s;
    ll k;
    cin>>s>>k;
    dp[0][0][0]=1;
    s='#'+s;
    for(int i=1;i<s.size();i++){
        for(int before=0;before<=k;before++){
            for(int digit=0;digit<=9;digit++){
                int after=before;
                if(digit!=0){
                    after++;
                }
                if(char('0'+digit)<s[i]){
                    dp[1][i][after]+=dp[0][i-1][before];
                    dp[1][i][after]+=dp[1][i-1][before];
                }
                if(char('0'+digit)==s[i]){
                    dp[0][i][after]+=dp[0][i-1][before];
                    dp[1][i][after]+=dp[1][i-1][before];
                }
                if(char('0'+digit)>s[i]){
                    dp[1][i][after]+=dp[1][i-1][before];
                }
            }
        }
    }
    ll ans=0;
    ans+=dp[0][s.size()-1][k];
    ans+=dp[1][s.size()-1][k];
    cout<<ans<<endl;
    return 0;
}
