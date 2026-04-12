#include<bits/stdc++.h>
using namespace std;using ll=long long;using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;using vvl=vector<vl>;using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;using vpl=vector<PL>;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/2;
constexpr int INF=inf<int>,MOD=1000000007;constexpr ll LINF=inf<ll>;
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...)_ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n)for(int i=n-1;i>=0;--i)
#define REPA(i,v)REP(i,v.size())
#define all(v)(v).begin(),(v).end()
#define bit(n)(1ll<<(n))
#define uniq(v)sort(all(v));v.erase(unique(all(v)),v.end())
#define F first
#define S second
#define endl '\n'
#define cho(n,a,b)cout<<((n)?a:b)<<endl
void YES(int n){cho(n,"YES","NO");}void Yes(int n){cho(n,"Yes","No");}void Poss(int n){cho(n,"Possible","Impossible");}
#ifndef LOCAL
struct osd{template<class T>osd&operator<(const T&t){return*this;}template<class T>osd&operator<<(const T&t){return*this;}};osd cer_;template<class...T>void _print(osd&a,T&&...t){}
#define cerr cer_
#endif
template<class T>ostream&operator<(ostream&o,const T&t){return o<<t;}template<class T>istream&operator>(istream&i,T&t){return i>>t;}
void _print(ostream&s){}template<class T,class...U>void _print(ostream&s,T&&t,U&&...u){s<t<(sizeof...(u)?' ':'\n');_print(s,u...);}
template<class...T>void print(T&&...t){_print(cout,t...);}template<class...T>void dprint(T&&...t){_print(cerr,t...);}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>ostream&operator<<(ostream&o,const vector<T>&v){for(auto&&i:v)o<i<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>j;return i;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<p.F<' '<p.S;}
template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>p.F>p.S;}
template<class T>ostream&operator<<(ostream&o,const set<T>&v){for(auto&&i:v)o<i<' ';return o;}
template<class T>vector<T>&operator<<(vector<T>&v,const T&t){v.push_back(t);return v;}
template<class T>queue<T>&operator<<(queue<T>&q,const T&t){q.push(t);return q;}template<class T>queue<T>&operator<<(T&t,queue<T>&q){t=q.front();q.pop();return q;}
template<class T>deque<T>&operator>>(const T&t,deque<T>&q){q.push_front(t);return q;}template<class T>deque<T>&operator<<(T&t,deque<T>&q){t=q.front();q.pop_front();return q;}
template<class T>deque<T>&operator<<(deque<T>&q,const T&t){q.push_back(t);return q;}template<class T>deque<T>&operator>>(deque<T>&q,T&t){t=q.back(t);q.pop_back();return q;}
template<class T>stack<T>&operator<<(stack<T>&s,const T&t){s.push(t);return s;}template<class T>stack<T>&operator>>(stack<T>&s,T&t){t=s.top();s.pop();return s;}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin>n;
    vi a(n);
    cin>a;
    multiset<int> s;
    REP(i,n){
        if(s.empty())s.insert(a[i]);
        else{
            auto it=s.lower_bound(a[i]);
            if(it==s.begin()){
                s.insert(a[i]);
            }else{
                auto jt=prev(it,1);
                s.erase(jt);
                s.insert(a[i]);
            }
        }
    }
    cout<s.size()<endl;
    return 0;
}
