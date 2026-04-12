#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<ll>>;
#define MAX 1000000007

int main()
{
    ll n;ll x,m;
    cin >> n >> x >> m;
    ll ans=0;
    ll loop_st;
    int loop_before=0;
    int loop_num=0;
    int loop_after=0;
    ll loop_vol=0;
    vector<bool> visit(m+1,false);
    if(n<m){
        rep(i,n){
            ans+=x;
            x*=x;
            x%=m;
        }
        cout << ans;
        return 0;
    }
    rep(i,m){
        if(visit[x]==false){
            ans+=x;
            visit[x]=true;
            x*=x;
            x%=m;
            loop_before++;
        }else if(x==0){
            cout << ans << endl;
            return 0;
        }else{
            loop_st=x;
            break;
        }
    }
    while(loop_num==0||x!=loop_st){
        loop_vol+=x;
        x*=x;
        x%=m;
        loop_num++;
    }
    ans+=loop_vol*((n-loop_before)/loop_num);
    loop_after=(n-loop_before)%loop_num;
    rep(i,loop_after){
        ans+=x;
        x*=x;
        x%=m;
    }
    cout << ans << endl;
}