#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo (1LL<<63-1)
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const long double Pi=acos(-1),e=2.718;
const int N=2e4+10,D=110,mod=1e9+7;
int n,d;
ll dp[N][D][2];
string s;
ll solve(int i,int mo,bool les){
    if(i==n){
        return (mo==0);
    }
    ll &ret = dp[i][mo][les];
    if(ret!=-1)return ret;
    ret = 0;
    if(les){
        for(int j=0;j<10;j++){
            ret += solve(i+1,(mo+j)%d,1);
            ret %= mod;
        }
    }
    else{
        for(int j=0;j<=s[i]-'0';j++){
            ret += solve(i+1,(mo+j)%d,(j<s[i]-'0'));
            ret %= mod;
        }
    }
    return ret;
}

int main ()
{
    FASTIO
    memset(dp,-1,sizeof dp);
    cin >> s >> d;
    n = s.si;
    cout << (solve(0,0,0)-1+mod)%mod << endl;
    return 0;
}
/**

*/
