#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 1,-1, 1,-1};
int dy[]={0, 1, 0, -1, 1, 1,-1,-1};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);
static mt19937 _g(time(nullptr));
 
inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }


int N;
vector<int> S,T;
vector<ull> U,V;
vector<string> us,vs;
void printMat(vector<vector<string>> M);
void printMat(vector<vector<ull>> M);
// bool checkMat(vector<vector<string>> M, int k);
bool checkMat(vector<vector<string>> M);

void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        __output += string("/output/") + string(__p.stem()) + string(".txt");
        freopen(__input.c_str(), "r", stdin);
        freopen(__output.c_str(), "w", stdout);
    #endif
    cin >> N;
    S = fetch_vec<int>(N);
    T = fetch_vec<int>(N);
    U = fetch_vec<ull>(N);
    V = fetch_vec<ull>(N);
    for(auto u:U) us.push_back(bitset<64>(u).to_string());
    for(auto v:V) vs.push_back(bitset<64>(v).to_string());
}

int solve(){
    // vector<vector<ull>> Mat(N,vector<ull>(N,0));
    // -1検出用。以降、チェックで矛盾する部分は出ないはず。
    // for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    // {
    //     if(S[i]==1 && T[j]==0) {if(U[i]&V[j]==V[j] && U[i]|V[j]==U[i]) continue; else cout << -1 << endl;}
    //     if(S[i]==0 && T[j]==1) {if(U[i]&V[j]==U[j] && U[i]|V[j]==V[i]) continue; else cout << -1 << endl;}

    // //     // if(S[i]==0 && T[j]==0) {Mat[i][j] = U[i]|V[j];}
    // //     // if(S[i]==1 && T[j]==0) {if(U[i]&V[j]==V[j] && U[i]|V[j]==U[i]) Mat[i][j] = U[i]&V[j]; else return -1;}
    // //     // if(S[i]==0 && T[j]==1) {if(U[i]&V[j]==U[j] && U[i]|V[j]==V[i]) Mat[i][j] = U[i]&V[j]; else return -1;}
    // //     // if(S[i]==1 && T[j]==1) {Mat[i][j] = U[i]&V[j];}
    // }

    string init(64,'x');
    vector<vector<string>> M(N,vector<string>(N, init));
    // vector<vector<string>> M(N,vector<string>(N,bitset<64>(0).to_string()));
    for (int k = 0; k < 64; k++)
    {
        vector<int> isAveirableRow(N,0);
        vector<int> isAveirableColumn(N,0);

        for (int i = 0; i < N; i++)
        {
            if(S[i]==0 && us[i][k]=='1') for(int j = 0; j < N; j++) M[i][j][k] = '1';
            if(S[i]==1 && us[i][k]=='0') for(int j = 0; j < N; j++) M[i][j][k] = '0';
            if(S[i]==1 && us[i][k]=='1') for(int j = 0; j < N; j++) if(T[j]==1 && vs[j][k]=='1') M[i][j][k] = '1';
            // if(S[i]==0 && us[i][k]=='0') continue; //どれか1つ1をもたないといけない。
        }

        for (int j = 0; j < N; j++)
        {
            // if(T[j]==0 && vs[j][k]=='1') for(int i = 0; i < N; i++) M[i][j][k] = '1';
            // if(T[j]==1 && vs[j][k]=='0') for(int i = 0; i < N; i++) M[i][j][k] = '0';
            if(T[j]==0 && vs[j][k]=='1') for(int i = 0; i < N; i++) {if(M[i][j][k]=='0') {return -1;} else {M[i][j][k] = '1';}}
            if(T[j]==1 && vs[j][k]=='0') for(int i = 0; i < N; i++) {if(M[i][j][k]=='1') {return -1;} else {M[i][j][k] = '0';}}
            if(T[j]==1 && vs[j][k]=='1') for(int i = 0; i < N; i++) if(S[i]==1 && us[i][k]=='1') M[i][j][k] = '1';
        }
        // ↑とりあえず、埋めれるところはうめとく。
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if(M[i][j][k]=='x') M[i][j][k]='0';
        // 未定の場所には0を埋める。
        for (int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(M[i][j][k]=='1') {isAveirableRow[i]++;isAveirableColumn[j]++;}

        // 各行が正しいのか、確認。
        for (int i = 0; i < N; i++)
        {
            if(S[i]==1 && us[i][k]=='1'){
                int u=0;
                for(int j = 0; j < N; j++) u |= (M[i][j][k]-'0');
                if(u==1) continue;
                else{
                    // 1にしてもいいけどすべて1になってはダメな列
                    bool ok=false;
                    for(int j=0;!ok && j<N;j++){
                        if(T[j]==0 && vs[j][k]=='0' && isAveirableColumn[j]<(N-1)) {
                            M[i][j][k]='1';
                            ok=true;
                            isAveirableColumn[j]++;
                            break;
                            }
                    }
                    if(!ok) return -1;      
                }
            }
        }

        // 各列が正しいのか、確認。
        for (int j = 0; j < N; j++)
        {
            if(T[j]==1 && vs[j][k]=='1'){
                int v=0;
                for (int i = 0; i < N; i++) v |= (M[i][j][k]-'0');
                if(v==1) continue;
                else{
                    // 1にしてもいいけどすべて1になってはダメな行
                    bool ok=false;
                    for(int i=0;!ok && i<N;i++){
                        if(S[i]==0 && us[i][k]=='0' && isAveirableRow[i]<(N-1)) {
                            M[i][j][k]='1';
                            ok=true;
                            isAveirableRow[i]++;
                            break;
                            }
                    }
                    if(!ok) return -1;
                }
            }
        }
        // check
        // if(!checkMat(M, k)) return -1;

    }
    // DBG(M)
    if(!checkMat(M)) return -1;
    printMat(M);
    return 0;
}

// bool checkMat(vector<vector<string>> M, int k){
//     for (int i = 0; i < N; i++)
//     {
//         ull u=0;
//         if(S[i]==0){u=~u; for(int j = 0; j < N; j++) u&=(M[i][j][k]-'0'); }
//         else{u=0; for(int j = 0; j < N; j++) u|=(M[i][j][k]-'0'); }
//         if(u!=(us[i][k]-'0')) return false;
//     }
//     for (int j = 0; j < N; j++)
//     {
//         ull v;
//         if(T[j]==0){v=~v; for(int i = 0; i < N; i++) v&=(M[i][j][k]-'0'); }
//         else{v=0; for(int i = 0; i < N; i++) v|=(M[i][j][k]-'0'); }
//         if(v!=(vs[j][k]-'0')) return false;
//     }
//     return true;
// }

bool checkMat(vector<vector<string>> M){
    ull u,v;
    for (int i = 0; i < N; i++)
    {
        u=0;
        if(S[i]==0){u=~u; for(int j = 0; j < N; j++) u&=bitset<64>(M[i][j]).to_ullong(); }
        else{u=0; for(int j = 0; j < N; j++) {u|=bitset<64>(M[i][j]).to_ullong();} }
        if(u!=U[i]) return false;
    }
    for (int j = 0; j < N; j++)
    {
        v=0;
        if(T[j]==0){v=~v; for(int i = 0; i < N; i++) v&=bitset<64>(M[i][j]).to_ullong(); }
        else{v=0; for(int i = 0; i < N; i++) v|=bitset<64>(M[i][j]).to_ullong(); }
        if(v!=V[j]) return false;
    }
    return true;
}

void printMat(vector<vector<string>> m){
    int n = m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << bitset<64>(m[i][j]).to_ullong() << " ";
        }
        cout << "\n";
    }
    return ;
}

void printMat(vector<vector<ull> > m){
    int n=m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return ;
}

void testcase(int n){
    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        // __output += string("/output/") + string(__p.stem()) + string(".txt");
        // freopen(__input.c_str(), "r", stdin);
        freopen(__input.c_str(), "w", stdout);
    #endif

    vector<int> s,t;
    vector<ull> u,v;
    for (int i = 0; i < n; i++)
    {
        s.push_back(randint(0LL,1LL));
        t.push_back(randint(0LL,1LL));
        u.push_back(randint(0LL,1LL));
        v.push_back(randint(0LL,1LL));
    }
    cout << n << endl;
    cout << s << endl;
    cout << t << endl;
    cout << u << endl;
    cout << v << endl;    
}

void valid_testcase(int n){

    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        // __output += string("/output/") + string(__p.stem()) + string(".txt");
        // freopen(__input.c_str(), "r", stdin);
        freopen(__input.c_str(), "w", stdout);
    #endif

    vector<vector<ull> > M(n, vector<ull>(n,0));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) M[i][j] = randint(0,1);       
    
    vector<int> s,t;
    vector<ull> U,V;
    for (int i = 0; i < n; i++)
    {
        s.push_back(randint(0LL,1LL));
        t.push_back(randint(0LL,1LL));
    }

    for (int i = 0; i < n; i++)
    {
        ull u=0;
        if(s[i]==0){u=~u; for(int j = 0; j < n; j++) u&=M[i][j]; }
        else{u=0; for(int j = 0; j < n; j++) u|=M[i][j]; }
        U.push_back(u);
    }

    for (int j = 0; j < n; j++)
    {
        ull v=0;
        if(t[j]==0){v=~v; for(int i = 0; i < n; i++) v&=M[i][j]; }
        else{v=0; for(int i = 0; i < n; i++) v|=M[i][j]; }
        V.push_back(v);
    }

    cout << n << endl;
    cout << s << endl;
    cout << t << endl;
    cout << U << endl;
    cout << V << endl;
    cout << endl;
    cout << n << endl;
    printMat(M);
}

// 実装が重い。
// 例外を処理する。
// テストをいくつか考えるの有用。
int main()
{
    // valid_testcase(3);
    input();
    int a = solve();
    if(a==-1) cout << a << endl;
    return 0;
}
