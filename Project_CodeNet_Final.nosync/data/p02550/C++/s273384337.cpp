#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

int used[100005];

int main(){
    rep(i,100005){
        used[i]=-1;
    }
    ll n;
    int x,m;
    cin >> n>> x>> m;
    bool lp=1;
    int cnt=0;
    vector<ll> temp;
    temp.push_back(x);
    ll A=x;
    used[x]=0;
    int repeat_start=0;
    while(lp){
        cnt++;
        A=A*A%m;
        //cerr<<A<<' ';
        temp.push_back(temp[temp.size()-1]+A);
        if(used[A]!=-1){
            lp=0;
            repeat_start=used[A];
            cnt=cnt-repeat_start;
        }
        used[A]=cnt;
        if(cnt==n-1){
            //cerr<<endl;
            cout<<temp[temp.size()-1]<<endl;
            return 0;
        }
    }
    ll ans=0;
    ans+=temp[repeat_start];
    n-=repeat_start+1;
    ans+=(temp[temp.size()-1]-temp[repeat_start])*(n/cnt);
    ans+=(temp[repeat_start+n%cnt]-temp[repeat_start]);
    cout<<ans<<endl;
    return 0;
}