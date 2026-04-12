#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
   
const ll Mod = 1e9 + 7;
const int N = 1e4 + 7;
const int D = 102;

ll dp[N][D] , ans[N][D];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    string s; cin >> s;
    int d; cin >> d;

    reverse(all(s));
    
    for(int i = 0 ;i <= 9 ; i++)
        dp[0][i%d]++;
    
    for(int i = 1; i < s.size() ; i++){
        for(int j = 0;j <= 9 ; j++){
            for(int k = 0 ;k < d ; k++){
                dp[i][k] += dp[i-1][(k-j+10*d)%d];
                if(dp[i][k] >= Mod)
                    dp[i][k] -= Mod;
                
            }
            
        }
    }

    for(int i = 0 ;i <= s[0]-'0' ; i++)
        ans[0][i%d]++;

    for(int i =1 ; i < s.size() ; i++){
        for(int k = 0 ; k < d; k++)
            ans[i][k] = ans[i-1][ (k-(s[i]-'0') + 10*d)%d];
        
        for(int j = 0 ;j < s[i]-'0' ; j++){
            for(int k = 0 ; k < d ; k++){
                ans[i][k] += dp[i-1][(k-j+10*d)%d];
                if(ans[i][k] >= Mod)
                    ans[i][k] -= Mod;
            }   
        }
    }
    cout << (ans[s.size()-1][0]-1+Mod)%Mod << endl;

    return 0;
}