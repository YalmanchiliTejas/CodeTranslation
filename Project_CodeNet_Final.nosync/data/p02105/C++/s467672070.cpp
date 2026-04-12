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
int main(){
    int N;
    cin>>N;
    LL X,Y;
    cin>>X>>Y;
    vector<vector<P>> xy(5,vector<P>(1,P(0,0)));
    REP(i,N){
        int t;LL x,y;
        cin>>t>>x>>y;
        xy[t-1].pb(P(x,y));
    }
    vector<P> A,B;
    for(auto &a:xy[0])
        for(auto &b:xy[1])
            for(auto &c:xy[2])A.pb(P(a.fi+b.fi+c.fi,a.se+b.se+c.se));
    for(auto &d:xy[3])
        for(auto &e:xy[4])B.pb(P(d.fi+e.fi,d.se+e.se));
    sort(ALL(A));
    sort(ALL(B));
    reverse(ALL(B));
    
    int M=B.size();
    multiset<LL> exist;
    int bg=0,ed=0;
    for(auto &a:A){
        while(ed<M&&a.fi+B[ed].fi>=X){
            exist.insert(B[ed].se);
            ed++;
        }
        while(bg<ed&&a.fi+B[bg].fi>Y){
            auto it = exist.find(B[bg].se);
            exist.erase(it);
            bg++;
        }
        auto it = exist.lower_bound(X-a.se);
        if(it!=exist.end()&&a.se+*it<=Y){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}