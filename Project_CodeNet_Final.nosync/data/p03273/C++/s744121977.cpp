#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define F first
#define S second
#define R cin>>
#define O cout<<
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())

// ループ系
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)

// #define fou(i,a,n) for(int i=a;i<n;i++)
#define elif(c) else if(c)


// 出力系
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
template<Z A>void PR1(A a){rep(i,a.size()){if(i)cout<<' ';cout<<a[i];}ln;}
template<Z A>void PR2(A a){rep(i, a.size()){PR1(a[i]);}}


ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}

const ll MAX=1000000007,MAXL=1LL<<61,dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};

typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
typedef vector<VC> VVC;




void Main() {
    int h, w; R h >> w;

    VVC a(h);
    char tmp;

    rep(i,h){
        rep(j, w){
            R tmp;
            a[i].pb(tmp);
        }
    }


    map<int, int> b, c;


    bool ok = false;

    rep(i, h){
        ok = false;
        rep(j, w){
            if (a[i][j] == '#') break;
            if (j == w-1) ok = true;
        }
        if (ok) b[i] = 1;
    }

    rep(i, w) {
        ok = false;
        rep(j, h) {
            if(a[j][i] == '#') break;
            if (j == h-1) ok = true;
        }
        if(ok) c[i] = 1;
    }


    rep(i, h){
        if (b[i] == 1) continue;
        rep(j, w){
            if (c[j] != 1) O a[i][j];
        }
        ln;
        
    }
    

}
 
int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}