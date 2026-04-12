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
//#define MOD 998244353
#define MOD 1000000007
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
const int SIZE=200050;
//↑templete
signed main(){

    ll N;
    cin>>N;
    vll A;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        A.pb(a);
    }

    ll DP[SIZE][3]={};
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<3;j++)
            DP[i][j]=-INFLL;
    }
    DP[0][0]=A[0];
    DP[1][1]=A[1];
    DP[2][2]=A[2];
    for(int i=2;i<N;i++){
        DP[i][0]=max(DP[i][0], DP[i-2][0]+A[i]);
        DP[i][1]=max(DP[i][1], DP[i-2][1]+A[i]);
        DP[i][2]=max(DP[i][2], DP[i-2][2]+A[i]);
        if(i-3<0)
            continue;
        DP[i][1]=max(DP[i][1], DP[i-3][0]+A[i]);
        DP[i][2]=max(DP[i][2], DP[i-3][1]+A[i]);
        if(i-4<0)
            continue;
        DP[i][2]=max(DP[i][2], DP[i-4][0]+A[i]);
    }

    ll ans=-INFLL;

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<N;j++)
    //         cout<<DP[j][i]<<" ";
    //     cout<<endl;
    // }

    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            if(j+1==(N/2)+(N/2)-1+i)
                ans=max(ans, DP[j][i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
