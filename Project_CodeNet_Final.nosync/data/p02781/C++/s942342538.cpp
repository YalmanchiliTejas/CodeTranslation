#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007
typedef pair<ll,ll> P;

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int dp[105][4][2];

int main(){
    string s;
    cin >> s;
    int t;
    cin >> t;
    int n;
    n=s.size();
    dp[0][0][0]=1;
    rep(i,n){
        rep(j,4){
            rep(k,2){
                int nd=s[i]-'0';
                rep(d,10){
                    int ni=i+1,nj=j,nk=k;
                    if(d!=0) nj++;
                    if(nj>t) continue;
                    if(nk==0){
                        if(nd<d) continue;
                        if(nd!=d) nk=1;
                    }
                    dp[ni][nj][nk]+=dp[i][j][k];
                }
            }
        }
    }
    
    cout << dp[n][t][0]+dp[n][t][1] << endl;
    
    return 0;
}









