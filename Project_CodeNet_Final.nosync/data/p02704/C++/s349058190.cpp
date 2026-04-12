#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> S(N),T(N);
    vector<ull> U(N),V(N);
    for (int i=0;i<N;++i) cin >> S[i];
    for (int i=0;i<N;++i) cin >> T[i];
    for (int i=0;i<N;++i) cin >> U[i];
    for (int i=0;i<N;++i) cin >> V[i];
    vector<vector<ull>> ans(N,vector<ull>(N,0));
    for (int k=0;k<64;++k){
        ull mask=1ULL<<k;
        vector<vector<int>> B(N,vector<int>(N,-1));
        vector<pair<int,int>> row,col;
        for (int i=0;i<N;++i){
            int nxt=(S[i]<<1)+((U[i]&mask)>>k);
            if (nxt==0){
                row.emplace_back(i,0);
            } else if (nxt==1){
                for (int j=0;j<N;++j) B[i][j]=1;
            } else if (nxt==2){
                for (int j=0;j<N;++j) B[i][j]=0;
            } else {
                row.emplace_back(i,1);
            }
        }
        for (int i=0;i<N;++i){
            int nxt=(T[i]<<1)+((V[i]&mask)>>k);
            if (nxt==0){
                col.emplace_back(i,0);
            } else if (nxt==1){
                for (int j=0;j<N;++j){
                    if (~B[j][i]&&B[j][i]!=1){
                        cout << -1 << '\n';
                        return 0;
                    }
                    B[j][i]=1;
                }
            } else if (nxt==2){
                for (int j=0;j<N;++j){
                    if (~B[j][i]&&B[j][i]!=0){
                        cout << -1 << '\n';
                        return 0;
                    }
                    B[j][i]=0;
                }
            } else {
                col.emplace_back(i,1);
            }
        }
        if (!row.size()||!col.size()){
            for (int i=0;i<N;++i){
                int nxt=(S[i]<<1)+((U[i]&mask)>>k);
                if (nxt==0){
                    int ok=0;
                    for (int j=0;j<N;++j) ok|=(B[i][j]==0);
                    if (!ok){
                        cout << -1 << '\n';
                        return 0;
                    }
                } else if (nxt==3){
                    int ok=0;
                    for (int j=0;j<N;++j) ok|=(B[i][j]==1);
                    if (!ok){
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            }
            for (int i=0;i<N;++i){
                int nxt=(T[i]<<1)+((V[i]&mask)>>k);
                if (nxt==0){
                    int ok=0;
                    for (int j=0;j<N;++j) ok|=(B[j][i]==0);
                    if (!ok){
                        cout << -1 << '\n';
                        return 0;
                    }
                } else if (nxt==3){
                    int ok=0;
                    for (int j=0;j<N;++j) ok|=(B[j][i]==1);
                    if (!ok){
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            }
        } else {
            int H=row.size(),W=col.size();
            vector<vector<int>> C(H,vector<int>(W));
            if (H==1){
                int ok=0;
                for (int i=0;i<N;++i) ok|=(B[row[0].first][i]==row[0].second);
                if (ok){
                    for (int i=0;i<W;++i) C[0][i]=col[i].second;
                } else {
                    for (int i=0;i<W;++i){
                        int fill=0;
                        for (int j=0;j<N;++j) fill|=(B[j][col[i].first]==col[i].second);
                        if (fill) C[0][i]=row[0].second;
                        else C[0][i]=col[i].second;
                        ok|=(C[0][i]==row[0].second);
                    }
                }
                if (!ok){
                    cout << -1 << '\n';
                    return 0;
                }
            } else if (W==1){
                int ok=0;
                for (int i=0;i<N;++i) ok|=(B[i][col[0].first]==col[0].second);
                if (ok){
                    for (int i=0;i<H;++i) C[i][0]=row[i].second;
                } else {
                    for (int i=0;i<H;++i){
                        int fill=0;
                        for (int j=0;j<N;++j) fill|=(B[row[i].first][j]==row[i].second);
                        if (fill) C[i][0]=col[0].second;
                        else C[i][0]=row[i].second;
                        ok|=(C[i][0]==col[0].second);
                    }
                }
                if (!ok){
                    cout << -1 << '\n';
                    return 0;
                }
            } else {
                for (int i=0;i<H;++i){
                    for (int j=0;j<W;++j){
                        C[i][j]=(i+j)&1;
                    }
                }
            }
            for (int i=0;i<H;++i){
                for (int j=0;j<W;++j){
                    B[row[i].first][col[j].first]=C[i][j];
                }
            }
        }
        for (int i=0;i<N;++i){
            for (int j=0;j<N;++j){
                ans[i][j]+=(ull)B[i][j]<<k;
            }
        }
    }
    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            cout << ans[i][j] << (j+1==N?'\n':' ');
        }
    }
    /*ull MAX=(1ULL<<64)-1;
    cerr << MAX << '\n';
    for (int i=0;i<N;++i){
        if (!S[i]){
            ull res=MAX;
            for (int j=0;j<N;++j) res&=ans[i][j];
            if (res!=U[i]) cerr << '#' << i << '\n';
        } else {
            ull res=0;
            for (int j=0;j<N;++j) res|=ans[i][j];
            if (res!=U[i]) cerr << '#' << i << '\n';
        }
    }
    for (int j=0;j<N;++j){
        if (!T[j]){
            ull res=MAX;
            for (int i=0;i<N;++i) res&=ans[i][j];
            if (res!=V[j]) cerr << '$' << j << '\n';
        } else {
            ull res=0;
            for (int i=0;i<N;++i) res|=ans[i][j];
            if (res!=V[j]) cerr << '$' << j << '\n';
        }
    }*/
}