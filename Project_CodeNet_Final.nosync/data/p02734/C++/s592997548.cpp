#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
#include <numeric>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 998244353
//#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
typedef vector<tint> vtint;
typedef vector<vint> vvint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=3050;
//↑templete
signed main(){

    int N, S;
    cin>>N>>S;
    ll A[SIZE]={};
    for(int i=0;i<N;i++)
        cin>>A[i];
    static ll DP[SIZE][SIZE]={};
    for(int i=0;i<N;i++){
        (DP[i][0]+=1LL)%=MOD;
        for(int s=0;s<=S;s++){
            (DP[i+1][s]+=DP[i][s])%=MOD;
            (DP[i+1][s+A[i]>S?S+1:s+A[i]]+=DP[i][s])%=MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<=N;i++)
        (ans+=DP[i][S])%=MOD;
    cout<<ans<<endl;

    return 0;
}
