#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
ll func(int & id, int terget, vector<vector<int>> & path, int &n){
    clog<<terget<<" -> ";
    int crid=id|(1<<terget);
    clog<<"\""<<crid<<"\" ";
    ll crans=0;
    if(crid==(1LL<<n)-1LL){
      //  clog<<terget<<" "<<1<<endl;
      clog<<"("<<terget<<")"<<" => "<<1<<endl;
        return 1LL;
    }
    for(auto itr=path[terget].begin();itr!=path[terget].end();itr++){
        if(!(crid&(1<<*itr))){
            crans+=func(crid,*itr,path,n);
        }
    }
    clog << "(" << terget << ")" << " => " << crans << endl;
    return crans;
}
 int main(){
    int n,m;
    ll ans=0LL;
    cin >>n>>m;
  
    vector<vector<int>>path(n);
    int bef1,bef2;
    int id=0;
    rep(i,m){
        cin>>bef1>>bef2;
        bef1--;
        bef2--;
        path[bef1].pb(bef2);
        path[bef2].pb(bef1);
    }
    ans=func(id,0,path,n);
    cout<<ans<<endl;
}