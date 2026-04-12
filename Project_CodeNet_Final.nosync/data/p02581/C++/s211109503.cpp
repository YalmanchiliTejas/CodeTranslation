#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
template<class T> using priority_queue_reverse = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = 1'000'000'000LL + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433L;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
vector<string> split(const string &str, const char delemiter) {vector<string> res;stringstream ss(str);string buffer; while( getline(ss, buffer, delemiter) ) res.push_back(buffer); return res;}
int msb(int x) {return x?31-__builtin_clz(x):-1;}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<int> A(3*N),B(N,-12345678);
    for(int i = 0; i < 3*N; ++i) cin >> A[i],A[i]--;
    auto dp = multivector(N,N,-12345678);
    corner(N==1,A[0]==A[1]&&A[1]==A[2]);
    int ans=0,maxi=0;
    vector<int> v;
    for(int i = 0; i < 5; ++i) v.push_back(A[i]);
    sort(ALL(v));
    do{
        int u = (v[2]==v[3]&&v[3]==v[4]);
        chmax(dp[v[0]][v[1]],u);
        chmax(maxi,u);
        chmax(B[v[0]],u);
        chmax(B[v[1]],u);
    } while(next_permutation(ALL(v)));
    

    for(int i=5; i+2 < 3*N; i+=3) {
        int a=A[i],b=A[i+1],c=A[i+2];
        if(a==b&&b==c) {
            ans++;
            continue;
        }
        vector<pair<int,int>> vp;
        if(a==b) {
            for(int j=0;j<N;++j) {
                vp.emplace_back(c*N+j,dp[a][j]+1);
            }
        }
        if(b==c) {
            for(int j=0;j<N;++j) {
                vp.emplace_back(a*N+j,dp[b][j]+1);
            }
        }
        if(c==a) {
            for(int j=0;j<N;++j) {
                vp.emplace_back(b*N+j,dp[c][j]+1);
            }
        }
        {
            vp.emplace_back(b*N+c,dp[a][a]+1);
        }
        {
            vp.emplace_back(c*N+a,dp[b][b]+1);
        }
        {
            vp.emplace_back(a*N+b,dp[c][c]+1);
        }
        {
            vp.emplace_back(a*N+b,maxi);
            vp.emplace_back(b*N+c,maxi);
            vp.emplace_back(c*N+a,maxi);
        }
        {
            for(int j=0;j<N;++j) {
                vp.emplace_back(a*N+j,B[j]);
                vp.emplace_back(b*N+j,B[j]);
                vp.emplace_back(c*N+j,B[j]);
            }
        }
        for(auto p:vp) {
            int s=p.first/N,t=p.first%N,u=p.second;
            chmax(dp[s][t],u);
            chmax(dp[t][s],u);
            chmax(maxi,u);
            chmax(B[s],u);
            chmax(B[t],u);
        }
    }
    int l=A[3*N-1];
    chmax(maxi,dp[l][l]+1);
    ans += maxi;
    cout << ans << endl;
    return 0;
}
