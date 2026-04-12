//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF =1e9;
const ll LINF=1e18;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a / gcd(a, b)*b;}
string s;
int k;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s>>k;
    int n=s.size();
    ll dp[n+1][k+1][2];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int l=0;l<2;l++){
                ll temp=s[i]-'0';
                if(j==k){//0を選ぶ
                    if(l==0){
                        if(temp==0){
                            dp[i+1][k][0]+=dp[i][k][l];
                        }
                        else{
                            dp[i+1][k][1]+=dp[i][k][l];
                        }
                    }
                    else{
                        dp[i+1][k][1]+=dp[i][k][l];
                    }
                }
                else{
                if(l==0){
                    if(temp==0){
                        dp[i+1][j][0]+=dp[i][j][l];
                    }
                    else{
                        dp[i+1][j][1]+=dp[i][j][l];
                        dp[i+1][j+1][0]+=dp[i][j][l];
                        dp[i+1][j+1][1]+=dp[i][j][l]*(temp-1);
                    }
                }
                else{
                        dp[i+1][j][1]+=dp[i][j][l];
                        dp[i+1][j+1][1]+=dp[i][j][l]*9;
                }
                }
            }
        }
    }
    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l=0;l<2;l++){
                cout<<dp[i][j][l]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    */
    cout <<dp[n][k][0]+dp[n][k][1] << "\n";
}

