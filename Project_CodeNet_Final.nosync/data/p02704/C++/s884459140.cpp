#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////
using ull=unsigned long long;
using umatrix=vector<vector<ull>>;
umatrix ans(505,vector<ull>(505));
vi s(502);
vi t(502);
vector<ull> u(502),v(502); 
void solve(){
    ll n;
    cin >> n;
    rp(i,n) cin >> s[i];
    rp(i,n) cin >> t[i];
    rp(i,n) cin >> u[i];
    rp(i,n) cin >> v[i];
    bool ok=true;
    if(n==1){
        if(u[0]!=v[0]) print(-1);
        else print(u[0]);
        return;
    }
    rp(i,64){
        matrix cand(n,Vi(n,-1));
        ll hctr=n,vctr=n;
        rp(j,n){
            if(s[j]==0&&((u[j]>>i)%2)==1)
            {fill(all(cand[j]),1); hctr--;}
            if(s[j]==1&&(u[j]>>i)%2==0)
            {fill(all(cand[j]),0); hctr--;}
        }
        rp(j,n){
            if(t[j]==0&&(v[j]>>i)&1){
                rp(k,n){
                    if(cand.at(k).at(j)==0){
                        ok=false;
                    }
                    cand.at(k).at(j)=1;
                }
                vctr--;
            }
            if(t[j]==1&&(v[j]>>i)%2==0){
                rp(k,n){
                    if(cand.at(k).at(j)==1){
                        ok=false;
                    }
                    cand.at(k).at(j)=0;
                }
                vctr--;
            }
        }
        if(hctr==1){
            if(vctr==n){
                bool zero=false,one=false;
                ll pos;
                rp(j,n){
                    if(cand.at(j).at(0)==1) one=true;
                    if(cand.at(j).at(0)==0) zero=true;
                    if(cand.at(j).at(0)==-1) pos=j;
                }
                if(one&&zero||one&&s[pos]==0) fill(all(cand[pos]),0);
                else if(zero&&s[pos]==1) fill(all(cand[pos]),1);
                else if(one){
                    ll onepos=-1;
                    rp(j,n){
                        if(t[j]==1) {onepos=j; break;}
                    }
                    if(onepos==-1)ok=false;
                    else{
                        rp(j,n){
                            if(j==onepos) cand.at(pos).at(j)=1;
                            else cand.at(pos).at(j)=0;
                        }
                    }
                }
                else{
                    ll zeropos=-1;
                    rp(j,n){
                        if(t[j]==0){zeropos=j; break;}
                    }
                    if(zeropos==-1)ok=false;
                    else{
                        rp(j,n){
                            if(j==zeropos) cand.at(pos).at(j)=0;
                            else cand.at(pos).at(j)=1;
                        }
                    }
                }
            }else{
                rp(j,n){
                    rp(k,n){
                        if(cand.at(j).at(k)!=-1) continue;
                        if(j==0) cand.at(j).at(k)=cand.at(1).at(k)^1;
                        else cand.at(j).at(k)=cand.at(j-1).at(k)^1;
                    }
                }
            }
        }
        else if(vctr==1){
            if(hctr==n){
                bool zero=false,one=false;
                ll pos;
                rp(j,n){
                    if(cand.at(0).at(j)==1) one=true;
                    if(cand.at(0).at(j)==0) zero=true;
                    if(cand.at(0).at(j)==-1) pos=j;
                }
                if(one&&zero||one&&t[pos]==0) 
                    rp(j,n) cand.at(j).at(pos)=0;
                else if(zero&&t[pos]==1)
                    rp(j,n) cand.at(j).at(pos)=1;
                else if(one){
                    ll onepos=-1;
                    rp(j,n){
                        if(s[j]==1) {onepos=j; break;}
                    }
                    if(onepos==-1)ok=false;
                    else{
                        rp(j,n){
                            if(j==onepos) cand.at(j).at(pos)=1;
                            else cand.at(j).at(pos)=0;
                        }
                    }
                }
                else{
                    ll zeropos=-1;
                    rp(j,n){
                        if(s[j]==0){zeropos=j; break;}
                    }
                    if(zeropos==-1)ok=false;
                    else{
                        rp(j,n){
                            if(j==zeropos) cand.at(j).at(pos)=0;
                            else cand.at(j).at(pos)=1;
                        }
                    }
                }
            }else{
                rp(j,n){
                    rp(k,n){
                        if(cand.at(j).at(k)!=-1) continue;
                        if(k==0) cand.at(j).at(k)=cand.at(j).at(1)^1;
                        else cand.at(j).at(k)=cand.at(j).at(k-1)^1;
                    }
                }
            }
        }
        else{
            bool grid=false;
            bool line=false;
            bool changed=false;
            rp(j,n){
                    grid=line;
                rp(k,n){
                    if(cand.at(j).at(k)!=-1) continue;
                    if(grid){
                        cand.at(j).at(k)=1;
                        grid=false;
                        changed=true;
                        continue;
                    }
                    else{
                        cand.at(j).at(k)=0;
                        grid=true;
                        changed=true;
                        continue;
                    }
                }
                if(changed){
                    line^=true;
                    changed=false;
                }
            }
        }
        rp(j,n){
            rp(k,n){
                ans.at(j).at(k)+=cand.at(j).at(k)*((ull)1<<i);
            }
        }
        //print(ans.at(1).at(0));
    }
    if(!ok){
        print(-1);
        return;
    }
    rp(i,n){
        rp(j,n){
            princ(ans.at(i).at(j));
        }
        cout << endl;
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}