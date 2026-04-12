#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

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
    os << '(' << p.first << ',' << p.second << ')';
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
#pragma endregion

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(3*N);
    for (int i=0;i<3*N;++i) cin >> A[i],--A[i];

    if (N==1){
        cout << (A[0]==A[1]&&A[1]==A[2]) << '\n';
        return 0;
    }

    vector<vector<int>> dp(N+1,vector<int>(N+1,-INF))
                        ,nxt(N+1,vector<int>(N+1,-INF));
    vector<int> Max(N,-INF);
    int whole=-INF,same=0;

    for (int k=0;k<N-1;++k){
        vector<pair<int,int>> s;
        auto update=[&](int x,int y,int a){
            nxt[x][y]=max(nxt[x][y],a);
            s.emplace_back(x,y);
        };
        if (!k){
            for (int i=0;i<5;++i){
                for (int j=i+1;j<5;++j){
                    set<int> cnt;
                    for (int l=0;l<5;++l){
                        if (l!=i&&l!=j){
                            cnt.emplace(A[l]);
                        }
                    }
                    update(A[i],A[j],(cnt.size()==1));
                }
            }
        } else {
            vector<int> v={A[3*k+2],A[3*k+3],A[3*k+4]};
            sort(v.begin(),v.end());
            if (v[0]==v[2]){++same; continue;}

            for (int i=0;i<2;++i){
                if (v[i]==v[i+1]){
                    int rest=(!i?v[2]:v[0]);
                    for (int j=0;j<N;++j){
                        update(j,rest,dp[v[i]][j]+1);
                        update(j,rest,dp[j][v[i]]+1);
                    }
                }
            }

            for (int i=0;i<3;++i){
                vector<int> rest;
                for (int j=0;j<3;++j){
                    if (i!=j){
                        rest.emplace_back(v[j]);
                    }
                }
                update(rest[0],rest[1],dp[v[i]][v[i]]+1);
            }

            for (int i=0;i<N;++i){
                for (int j=0;j<3;++j){
                    update(i,v[j],Max[i]);
                }
            }

            for (int i=0;i<3;++i){
                for (int j=i+1;j<3;++j){
                    update(v[i],v[j],whole);
                }
            }
        }
        for (auto p:s){
            int x=p.first,y=p.second;
            dp[x][y]=max(dp[x][y],nxt[x][y]);
            Max[x]=max(Max[x],dp[x][y]);
            Max[y]=max(Max[y],dp[x][y]);
        }
        for (int i=0;i<N;++i) whole=max(whole,Max[i]);
    }

    int ans=0;
    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            ans=max(ans,dp[i][j]+(i==A[3*N-1]&&j==A[3*N-1]));
        }
    }
    cout << ans+same << '\n';
}
