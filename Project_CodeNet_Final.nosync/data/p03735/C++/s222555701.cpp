#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

typedef pair<LL,LL> P;
LL check(vector<P>& v){
    int n = v.size();
    LL res=1e18;
    REP(bit,1<<n){
        LL a=1e18,b=0,c=1e18,d=0;
        REP(i,n){
            LL x = v[i].fi;
            LL y = v[i].se;
            if((bit>>i)&1)swap(x,y);
            chmax(b,x);
            chmax(d,y);
            chmin(a,x);
            chmin(c,y);
        }
        chmin(res,(b-a)*(d-c));
    }
    return res;
}

unsigned yy=1145141919;
inline unsigned xorshift(){yy=yy^(yy<<13);yy=yy^(yy>>17);return yy=yy^(yy<<5);}
#define MASK 65535
inline int randInt(){return (int) (xorshift()&MASK);}
inline double randDouble(){return (xorshift()&MASK) /(double)MASK;}

int main(){    
    while(1){
        int N;
        DEBUG N=randInt()%4+2;
        else
            cin>>N;
        
        vector<P> x(N);
        LL bottom=1e12,top=0;
        REP(i,N){
            LL a,b;
            DEBUG a=randInt()%20+1,b=randInt()%20+1;
            else  cin>>a>>b;
            x[i]=minmax(a,b);
            chmin(bottom,x[i].fi);
            chmax(top,x[i].se);
        }
        sort(ALL(x));

        LL res;
        {
            LL latte=1e12,malta=0;
            REP(i,N)chmin(latte,x[i].se);
            REP(i,N)chmax(malta,x[i].fi);
            res=(top-latte)*(malta-bottom);
        }
        {
            set<P> s;
            REP(i,N)s.insert(P(x[i].fi,i));
            while(s.begin()->se>=0){
                LL nxt=x[s.begin()->se].se;
                chmin(res,(top-bottom)*(s.rbegin()->fi-s.begin()->fi));
                s.erase(*s.begin());
                s.insert(P(nxt,-1));
            }
            chmin(res,(top-bottom)*(s.rbegin()->fi-s.begin()->fi));

        }
    
        DEBUG {
            if(res==check(x))continue;
            else {
                REP(i,N){
                    cout<<x[i].fi<<" "<<x[i].se<<endl;
                }
                cout<<check(x)<<endl;
            }
        }
        cout<<res<<endl;
        return 0;
    }
    return 0;
}
