//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v){
    if(v.empty()){
        os<<"{ }";
        return os;
    }
    os<<"{"<<v.front();
    for(auto itr=++v.begin();itr!=v.end();itr++){
        os<<", "<<*itr;
    }
    os<<"}";
    return os;
}

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,x,m,ans=0; cin>>n>>x>>m;
    vector<ll> me(0);
    set<ll> st;
    ll cur=x%m;
    rep(_,m+1){
        if(st.count(cur)){
            break;
        }
        st.insert(cur);
        me.push_back(cur);
        cur=cur*cur%m;
    }
    ll idx=0,N=me.size();
    rep(i,m+1){
        if(cur==me[i]){
            idx=i;
            break;
        }
        ans+=me[i];
    }
    if(n<idx){
        ll aa=0;
        rep(i,n) aa+=me[i];
        cout<<aa<<endl;
        return 0;
    }
    ll roop=N-idx;
    ll roopsum=0;
    for(int i=idx;i<N;i++) roopsum+=me[i];
    ans+=roopsum*((n-idx)/roop);
    rep(i,(n-idx)%roop) ans+=me[idx+i];
    cout<<ans<<endl;
}