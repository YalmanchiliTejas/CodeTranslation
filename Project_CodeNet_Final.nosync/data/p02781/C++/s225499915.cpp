#include<bits/stdc++.h>
using namespace std;using ll=long long;using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;using vvl=vector<vl>;using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;using vpl=vector<PL>;
#define pqueue priority_queue
template<typename T>constexpr auto inf=numeric_limits<T>::max()/2;constexpr int INF=inf<int>,MOD=1000000007;constexpr ll LINF=inf<ll>;
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...)_ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n)for(int i=n-1;i>=0;--i)
#define REPA(i,v)REP(i,(v).size())
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define bit(n)(1ll<<(n))
#define F first
#define S second
#define endl '\n'
#define cho(n,a,b)cout<<((n)?a:b)<<endl
void YES(int n){cho(n,"YES","NO");}void Yes(int n){cho(n,"Yes","No");}void Poss(int n){cho(n,"Possible","Impossible");}
void _print(ostream&){}template<class T,class...U>void _print(ostream&s,const T&t,const U&...u){s<<t<<(sizeof...(u)?' ':'\n');_print(s,u...);}
template<class...T>void print(const T&...t){_print(cout,t...);}template<class...T>void dprint(const T&...t){_print(cerr,t...);}
#ifndef LOCAL
struct osd{template<class T>osd&operator<<(const T&t){return*this;}};osd cer_;
#define dprint(...)
#define cerr cer_
#endif
#define dbg(x) dprint("@l",__LINE__,':',#x,'=',x)
template<class T>bool chmax(T&a,const T&b){bool x=a<b;x?a=b:b;return x;}template<class T>bool chmin(T&a,const T&b){bool x=a>b;x?a=b:b;return x;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<p.F<<' '<<p.S;}template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>>p.F>>p.S;}
template<class T>class iterable{static false_type c(string v);template<class U>static auto c(U v)->decltype(all(v),true_type());static false_type c(...);public:const static bool value=decltype(c(declval<T>()))::value;};
template<class T,enable_if_t<iterable<T>::value,int> =0>ostream&operator<<(ostream&o,const T&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>>j;return i;}template<class T>vector<T>&operator<<(vector<T>&v,const T&t){v.push_back(t);return v;}
template<class T,class U>queue<T,U>&operator<<(queue<T,U>&v, const T&t){v.push(t);return v;}template<class T,class U>queue<T,U>&operator>>(queue<T,U>&v, T&t){t=v.front();v.pop();return v;}
template<class T,class U,class V>pqueue<T,U,V>&operator<<(pqueue<T,U,V>&v, const T&t){v.push(t);return v;}template<class T,class U,class V>pqueue<T,U,V>&operator>>(pqueue<T,U,V>&v, T&t){t=v.front();v.pop();return v;}
template<class T,class U>stack<T,U>&operator<<(stack<T,U>&v, const T&t){v.push(t);return v;}template<class T,class U>stack<T,U>&operator>>(stack<T,U>&v, T&t){t=v.front();v.pop();return v;}
template<class T,class U,class V>set<T,U,V>&operator<<(set<T,U,V>&v,const T&t){v.insert(t);return v;}template<class T,class U,class V>multiset<T,U,V>&operator<<(multiset<T,U,V>&v,const T&t){v.insert(t);return v;}
template<class T,enable_if_t<is_integral<T>::value,int> =0>T mod(T a, T b){if(a>0)return a%b;return b-(-a%b);}template<class T,enable_if_t<is_floating_point<T>::value,int> =0>T mod(T a, T b){if(a>0)return fmod(a,b);return b-fmod(-a,b);}
template<class T,class U>pair<T,U>&operator+=(pair<T,U>&a, pair<T,U>&b){a.F+=b.F;a.S+=b.S;return a;}template<class T,class U>pair<T,U>operator+(const pair<T,U>&a, const pair<T,U>&b){T r=a;return r+=b;}
template<class T,class U>pair<T,U>&operator-=(pair<T,U>&a, pair<T,U>&b){a.F-=b.F;a.S-=b.S;return a;}template<class T,class U>pair<T,U>operator-(const pair<T,U>&a, const pair<T,U>&b){T r=a;return r-=b;}
template<class T,class U>pair<T,U>operator-(const pair<T,U>&a){return mp(-a.F, -a.S);}
template<class T,class U>double std::norm(const pair<T,U>&p){return norm(p.F)+norm(p.S);}template<class T,class U>double std::abs(const pair<T,U>&p){return sqrt(norm(p));}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cout<<setprecision(10);
    string n;int k;
    cin>>n>>k;
    int m=n.size();
    string s(m, '0');
    ll a=0;
    switch(k){
        case 1:
            // REP(i,m-2){
            //     REP(ii,1,10){
            //         s[i]=ii+'0';
            //         if(s>=n)break;
            //         REP(j,i,m-1){
            //             REP(jj,1,10){
            //                 s[j]=jj+'0';
            //                 if(s>=n)break;
                            REP(k,m){
                                REP(kk,1,10){
                                    s[k]=kk+'0';
                                    if(s>n)break;
                                    // dprint(s);
                                    ++a;
                                }
                                s[k]='0';
                            }
            //             }
            //             s[j]='0';
            //         }
            //     }
            //     s[i]='0';
            // }
            break;
        case 2:
            // REP(i,m-2){
            //     REP(ii,1,10){
            //         s[i]=ii+'0';
            //         if(s>=n)break;
                    REP(j,m-1){
                        REP(jj,1,10){
                            s[j]=jj+'0';
                            if(s>=n)break;
                            REP(k,j+1,m){
                                REP(kk,1,10){
                                    s[k]=kk+'0';
                                    if(s>n)break;
                                    // dprint(s);
                                    ++a;
                                }
                                s[k]='0';
                            }
                        }
                        s[j]='0';
                    }
            //     }
            //     s[i]='0';
            // }
            break;
        case 3:
            REP(i,m-2){
                REP(ii,1,10){
                    s[i]=ii+'0';
                    if(s>=n)break;
                    REP(j,i+1,m-1){
                        REP(jj,1,10){
                            s[j]=jj+'0';
                            if(s>=n)break;
                            REP(k,j+1,m){
                                REP(kk,1,10){
                                    s[k]=kk+'0';
                                    if(s>n)break;
                                    // dprint(s);
                                    ++a;
                                }
                                s[k]='0';
                            }
                        }
                        s[j]='0';
                    }
                }
                s[i]='0';
            }
            break;
    }
    cout<<a<<endl;

}
