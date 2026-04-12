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

int main(){
    int n,m;cin >> n >> m;
    vii G(10,vi(10));

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = G[b][a] = 1;
    }

    int ans = 0;
    vi ord(n);
    iota(ALL(ord),0);
    do{
        if(ord[0]!=0)break;
        int exist = true;
        for(int i=0;i<n-1;i++){
            int from = ord[i];
            int to = ord[i+1];
            if(G[from][to]!=1)exist = false;
        }
        if(exist)ans++;
    }while(next_permutation(ALL(ord)));

    cout << ans << endl;
    return 0;
}