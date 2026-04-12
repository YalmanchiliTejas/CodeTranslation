#define debug_interval ','
#define dump_interval ' '
#define debug_toggle 1
//{
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX LLONG_MAX
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define fi first
#define se second
#define mp make_pair
#define rev reverse
#define dans dump(ans)

//{
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class...A> inline void dump(){cout<<endl;}
template<class...A> inline void dump_rest() {cout<<endl;}
template<class T, class...A> inline void dump_rest(const T& first, const A&... rest){cout<<dump_interval<<first;dump_rest(rest...);}
template<class T,class...A> inline void dump(const T&first,const A&...rest){cout<<first;dump_rest(rest...);}
template<class...A> inline void debug(){cerr<<endl;}
template<class...A> inline void debug_rest() {cerr<<endl;}
template<class T, class...A> inline void debug_rest(const T& first, const A&... rest){cerr<<debug_interval<<first;debug_rest(rest...);}
template<class T,class...A> inline void debug(const T&first,const A&...rest){if(debug_toggle)cerr<<first,debug_rest(rest...);}
//}

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
template<int m>class mint{
    private:
        int i;
    public:
        mint() : i(0){}
        mint(int i):i((i%m+m)%m){}
        mint operator+(const mint& o){return o.i+i;}
        mint operator*(const mint& o){return o.i*i;}
        mint operator-(){return -i;}operator int() {return i;}
        mint& operator+=(const mint& o){
            i = ((i + o.i)%m + m)%m;
            return *this;
        }
        mint& operator-=(const mint& o){
            i = ((i - o.i)%m + m)%m;
            return *this;
        }
};

//}

//typedef mint<1234567> itn;

int h,w;
bool nh[100],nw[100];

main(){
    cin>>h>>w;
    char m[h][w];
    rep(i,h)rep(j,w)cin>>m[i][j];
    rep(i,h){
        bool f=false;
        rep(j,w){
            if(m[i][j]=='#'){
                f=true;
                continue;
            }
        }
        nh[i]=f;
    }
    rep(i,w){
        bool f=false;
        rep(j,h){
            if(m[j][i]=='#'){
                f=true;
                continue;
            }
        }
        nw[i]=f;
    }
    rep(i,h){
        rep(j,w){
            if(nw[j]&&nh[i])cout<<m[i][j];
        }
        cout<<endl;
    }
}


