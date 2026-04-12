#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set>
 
using namespace std;
 
#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define f first
#define s second
 
#ifdef __BORLANDC__
    typedef __int64 ll;
#else
    typedef long long ll;
#endif
 
typedef pair<ll,ll> pii;
 
const int N = 7;
const int M = 7;
const int W = 11111;
const int T = 11111;
const ll INF = 1e16;
 
int n,m,w,t;
 
pii item[M];
int shop[N][M];
pii pos[N];
 
map<string,int> dict;
 
 
bool Contain(int state, int i){
    return (state&(1<<i))>0;
}
 
 
ll memo[(1<<N)][N];
 
void InitMemo(){
    rep(i,(1<<N))rep(j,N)memo[i][j]=-1;
}
 
 
ll GetRoot(int state, int num){
    if(state==0)return 0;
    if(state==(1<<num))return abs(pos[num].f) + abs(pos[num].s);
    if(memo[state][num]!=-1)return memo[state][num];
     
    ll ret = INF;
     
    state -= (1<<num);
     
    rep(i,n){
        if(Contain(state,i)){
            int dist = abs(pos[num].f - pos[i].f) + abs(pos[num].s - pos[i].s);
            ret = min(ret, GetRoot(state, i) + dist);
        }
    }
     
     
    return memo[state][num] = ret;
}
 
ll GetTime(int state){
     
    if(state==0)return false;
     
    ll ans = INF;
     
    rep(i,n){
        if(Contain(state,i)){
            ans = min(ans, GetRoot(state,i) + abs(pos[i].f)+abs(pos[i].s));
        }
    }
     
    return ans;
}
 
 
ll GetValue(int state){
     
    int has[M] = {0};
     
    rep(i,n){
        if(!Contain(state,i))continue;
        rep(j,m){
            has[j] = max(has[j], shop[i][j]);
        }
    }
     
     
    ll dp[W]={0};
    ll ans = 0;
     
    rep(i,w+1){
        rep(j,m){
            if(i+item[j].f > w)continue;
            dp[(int)(i+item[j].f)] = max(dp[(int)(i+item[j].f)], dp[i]+has[j]);
             
        }
        ans = max(ans, dp[i]);
    }
     
    return ans;
}
 
 
vector<pii> GetCand(){
     
    vector<pii> ret;
     
    rep(i,(1<<n)){
        ll a = GetTime(i);
        ll b = GetValue(i);
         
        if(a>=INF)continue;
        ret.push_back(pii(a,b));
    }
     
    return ret;
}
 
ll solve(){
    vector<pii> cand = GetCand();
     
    /*
    rep(i,cand.size()){
        cout<<"***"<<cand[i].f<<" "<<cand[i].s<<endl;
    }
    */
     
     
    ll dp[T] = {0};
    ll ans = 0;
    rep(i,t+1){
        rep(j,cand.size()){
            int a = cand[j].f;
            int b  =cand[j].s;
            if(i+a>t)continue;
            dp[i+a] = max(dp[i+a], dp[i]+b);
             
        }
        ans = max(ans,dp[i]);
    }
     
    return ans;
}
 
 
bool input(){
    cin>>n>>m>>w>>t;
     
    rep(i,m){
        string s;
        cin>>s>>item[i].f>>item[i].s;
         
        dict[s] = i;
    }
     
    rep(i,n){
        int a;
        cin>>a;
        cin>>pos[i].f>>pos[i].s;
        rep(j,m)shop[i][j]=0;
        rep(j,a){
            string s;
            int p;
            cin>>s>>p;
            int num = dict[s];
            shop[i][num] = item[num].s-p;
        }
    }
     
     
    return true;
}
 
 
int main(){
     
    InitMemo();
     
     
    input();
     
     
    cout<<solve()<<endl;
}