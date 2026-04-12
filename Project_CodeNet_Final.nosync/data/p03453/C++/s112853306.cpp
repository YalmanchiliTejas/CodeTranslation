#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> inline bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> inline bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

struct modint{
    using i64=int_fast64_t;
    i64 a;
    static constexpr i64 MOD=1e9+7;
    constexpr modint():a(){}
    constexpr modint(i64 a_):a(a_%MOD){
        if(a<0) a+=MOD;
    }
    constexpr modint inv()const noexcept{
        i64 n=1,m=MOD-2,A=a;
        while(m){
            if(m&1)(n*=A)%=MOD;
            (A*=A)%=MOD;
            m>>=1;
        }
        modint y;
        y.a=n;
        return y;
    }
    constexpr modint operator+()noexcept{
        return *this;
    }
    constexpr modint operator-()noexcept{
        modint tmp{};
        if(a) tmp.a=MOD-a;
        return tmp;
    }
    constexpr modint& operator++()noexcept{
        ++a;
        if(a==MOD) a=0;
        return *this;
    }
    constexpr modint& operator--()noexcept{
        if(a) --a;
        else a=MOD-1;
        return *this;
    }
    constexpr modint operator++(int)noexcept{
        modint tmp=*this;
        ++a;
        if(a==MOD) a=0;
        return tmp;
    }
    constexpr modint operator--(int)noexcept{
        modint tmp=*this;
        if(a) --a;
        else a=MOD-1;
        return tmp;
    }
    constexpr bool operator==(const modint& x)const noexcept{
        return a==x.a;
    }
    constexpr bool operator!=(const modint& x)const noexcept{
        return a!=x.a;
    }
    constexpr modint operator+(const modint& x)const noexcept{
        modint y;
        y.a=a+x.a;
        if(y.a>=MOD) y.a-=MOD;
        return y;
    }
    constexpr modint operator-(const modint& x)const noexcept{
        modint y;
        y.a=a-x.a;
        if(y.a<0) y.a+=MOD;
        return y;
    }
    constexpr modint operator*(const modint& x)const noexcept{
        modint y;
        y.a=(a*x.a)%MOD;
        return y;
    }
    constexpr modint operator/(const modint& x)const noexcept{
        modint y;
        y.a=(a*x.inv().a)%MOD;
        return y;
    }
    constexpr modint& operator+=(const modint& x)noexcept{
        a+=x.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint& x)noexcept{
        a-=x.a;
        if(a<0) a+=MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint& x)noexcept{
        (a*=x.a)%=MOD;
        return *this;
    }
    constexpr modint& operator/=(const modint& x)noexcept{
        (a*=x.inv().a)%=MOD;
        return *this;
    }
};
istream& operator>>(istream &in,modint& x)noexcept{
    static int_fast64_t a_;
    in>>a_;
    modint y(a_);
    x=y;
    return in;
}
ostream& operator<<(ostream &out,const modint& x)noexcept{
    out<<x.a;
    return out;
}
constexpr modint pwr(int_fast64_t a,int_fast64_t b)noexcept{
    modint _;
    int_fast64_t n=1,A=a;
    while(b){
        if(b&1) (n*=A)%=modint::MOD;
        (A*=A)%=modint::MOD;
        b>>=1;
    }
    _.a=n;
    return _;
}

template <class U,class C>
inline vector<pair<U,C>> dkstr(vector<vector<pair<int,U>>>& v,int n,int s,U inf){
    vector<pair<U,C>> d(n,make_pair(inf,0));
    d[s]=make_pair(0,1);
    priority_queue<pair<U,int>,vector<pair<U,int>>,greater<>> pq;
    pq.emplace(0,s);
    while(!pq.empty()){
        U D;
        int i;
        tie(D,i)=pq.top();pq.pop();
        C c=d[i].second;
        tie(ignore,c) = d[i];
        if(d[i].first<D) continue;
        for(auto q:v[i]){
            if(d[q.first].first<D+q.second) continue;
            if(d[q.first].first==D+q.second) d[q.first].second+=c;
            else if(d[q.first].first>D+q.second){
                d[q.first]=make_pair(D+q.second,c);
                pq.emplace(D+q.second,q.first);
            }
        }
    }
    return d;
}

template<class T>short sgn(T x){
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,s,t,u,v;
    ll a,b,d;
    cin>>n>>m>>s>>t;--s,--t;
    vector<vector<pair<int,ll>>> e(n);
    vector<pair<int,int>> E(m);
    vector<int> W(m);
    fr(i,m){
        cin>>u>>v>>d;
        E[i]={--u,--v};
        W[i]=d;
        e[u].emplace_back(v,d);
        e[v].emplace_back(u,d);
    }
    auto ds=dkstr<ll,modint>(e,n,s,1ll<<60);
    auto dt=dkstr<ll,modint>(e,n,t,1ll<<60);
    modint ans;
    tie(d,ans) = ds[t];
    ans*=ans;
    fr(i,n) if(ds[i].first*2==d){
        ans-=ds[i].second*dt[i].second*ds[i].second*dt[i].second;
    }
    fr(i,m){
        tie(u,v) = E[i];
        a=ds[u].first,b=dt[v].first;
        if(sgn(a*2-d)==sgn(b*2-d)){
            if(a*2>d) swap(u,v);
            if(ds[u].first+dt[v].first+W[i]!=d) continue;
            ans-=ds[u].second*dt[v].second*ds[u].second*dt[v].second;
        }
    }
    cout<<ans<<endl;
}