/* 
 Author:N_o_o_B 
 Created:September 27 2019 20:41:08
*/
#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) { cerr<<"[ "; __trace__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.first<<","<<x.second<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
void __trace__(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void __trace__(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    __trace__(names.substr(1+(int)name.size()), args...);
}
#else
    #define trace(args...)
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<vl> vvl;
#define fori(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define ford(i,n)  for(int i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
clock_t time_p=clock();
void time_taken()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
const ll mod=1e9+7;
const ll INF=1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout.precision(12);cout << fixed;
    string s;
    cin >> s;
    int n=s.size();
    int d;
    cin >> d;
    vector<vvl> dp(n+1,vvl(d,vl(2)));
    dp[n][0][0]=dp[n][0][1]=1;
    ford(i,n){
        fori(j,d){
            int lmt=s[i]-'0';
            fori(k,lmt+1){
                if(k!=lmt) dp[i][j][0]+=dp[i+1][(j-k%d+d)%d][1];
                else dp[i][j][0]+=dp[i+1][(j-k%d+d)%d][0];
                if(dp[i][j][0]>=mod) dp[i][j][0]-=mod;
            }
            lmt=9;
            fori(k,lmt+1){
                dp[i][j][1]+=dp[i+1][(j-k%d+d)%d][1];
                if(dp[i][j][1]>=mod) dp[i][j][1]-=mod;
            }
        }   
    }
    cout << (dp[0][0][0]-1+mod)%mod << endl;
    time_taken();
    return 0;
}