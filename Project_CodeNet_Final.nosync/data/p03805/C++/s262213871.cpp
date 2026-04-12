#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
 
const ll INF = 1LL<<60;
const int mINF = 1e9;
const int MOD = 1e9+7;

using vi = vector<int>;
using vii = vector<vi>;

template<typename T> 
bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> 
bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T GCD(T a,T b){ return b ? GCD(b,a%b) : a ;}
template<typename T>
T LCM(T a,T b){ return a*b / GCD(a,b) ;}

template<typename T>//文字列の置換/Boost:replace_all()
T replace_str(T str, string target, string str_to) {
    string::size_type pos = 0;
    while (pos = str.find(target, pos), pos != string::npos) {
        str.replace(pos, target.length(), str_to);
        pos += str_to.length();
    }
    return str;
}

vector<bool> seen;
vii G;
int ans = 0;

void dfs(int v){
    bool end = true;
    for(int i=0;i<seen.size();i++){
        if(!seen[i]&&i!=v)end = false;
    }
    if(end){
        ans++;
        return;
    }
    
    seen[v] = true;
    for(auto nv : G[v]){
        if(seen[nv])continue;
        dfs(nv);
    }
    seen[v] = false;
    return;
}

int main(){
    int n,m;cin >> n >> m;
    G.assign(n,vi());
    seen.assign(n,false);

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0);
    cout << ans << endl;
    return 0;
}