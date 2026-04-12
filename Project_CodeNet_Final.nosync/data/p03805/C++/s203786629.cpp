#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const int inf = 99999999;
const ll linf = 999999999999999999;
const double pi = acos(-1);
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

#define p_queue(i) priority_queue<i> 
#define rp_queue(i) priority_queue<i, vector<i>, greater<i>> 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define mod(i) ((i)%(ll)(1e9 + 7))
#define divm(a,b) (mod(a * modpow((ll)b,(ll)(1e9+5))))
#define rsort(a,b,c) sort(a, b, greater<c>())
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.end(), v.begin());
#define ft first
#define sd second
#define pb push_back
#define it insert
#define sz(x) ((int)(x).size())
#define lb(a,n,k) (lower_bound(a,a+n,k) - a) 
#define vlb(a,k)  (lower_bound(a.begin(),a.end(),k) - a.begin())
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return

ll modpow(ll i,ll j){ ll tmp=1; while(j){ if(j%2)tmp=mod(tmp*i);i=mod(i*i);j/=2;}return tmp;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

///////////////////////////////////////////////////////////////////////////
int n,m;
int v[10][10] = {};

ll dfs(int s,int use,ll cnt){
//cout << s << " " << use << " " << cnt << endl;
   if(use == (1<<n)-1){
   //if(cnt >= n-1 && s == n-1){
        ret 1;
    }
    
    ll ans = 0;
    rep(i,0,n){
        if(v[s][i] == 1 && !((use >> i) & 0x01)){
            ans += dfs(i,use|(1<< i),cnt+1);
        }
    }
  
    ret ans;
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }

    P(dfs(0,1,0));
	return  0;
}