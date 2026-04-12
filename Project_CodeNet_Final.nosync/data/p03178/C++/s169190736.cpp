#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <string.h>
#include<iomanip>
#include <iterator>

#define all(a) a.begin(),a.end()
#define VV(T) vector<vector< T > >
#define rep(i,N) for(int i = 0; i <N; i++)
#define name(x) #x
using namespace std;


const int INF = INT_MAX;
const long long INFL = (1LL<<40);
const int MOD = pow(10,9)+7;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

typedef long long ll,LL;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pLL;


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) is >> x;
    return is;
}
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(int i=0; i<vec.size(); i++){
        os << vec[i] << ( i+1 == vec.size() ? "" : " " );
    }
    return os;
}




const ll MAX_SIZE = 10005;
ll memo[MAX_SIZE][2][105];
string K;
ll D;
VV(ll) A;



int main() {
    
    
   
    cin >> K;
    cin >> D;
    
    // Kの桁分解。
    vector<ll> dig;
    vector<ll>cumsum;
    dig.push_back((K[0]-'0'));
    for(auto i = 1; i<K.size(); i++){
        dig.push_back(K[i] - '0');
    }
    cumsum.push_back(dig[0]%D);
    for(auto i = 1; i<K.size(); i++){
        cumsum.push_back((cumsum[i-1]+dig[i])%MOD);
    }
    
    
    reverse(all(dig));
    reverse(all(cumsum));
    ll N = (ll)K.size();
    
    memo[N-1][1][dig[N-1]%D] = 1;
    for(auto i = 0; i<dig[N-1];i++){
        memo[N-1][0][i%D] += 1;
        memo[N-1][0][i%D] %=MOD;
    }
    
    for(auto n = N-2;n>=0;n--){
        memo[n][1][cumsum[n]%D] = 1;
        for(auto i =0; i<D; i++){
            for(auto j = 0; j<dig[n];j++){
                memo[n][0][(i+j)%D] += memo[n+1][1][i];
                memo[n][0][(i+j)%D] %=MOD;
            }
            
            for(auto j = 0; j<10;j++){
                memo[n][0][(i+j)%D] += memo[n+1][0][i];
                memo[n][0][(i+j)%D] %=MOD;
            }
        }

    }
    
    ll ans = (memo[0][1][0] + memo[0][0][0] - 1);
    
    if(ans <0) ans += MOD;
    
    cout << ans %MOD << endl;
    
    return 0;
}









