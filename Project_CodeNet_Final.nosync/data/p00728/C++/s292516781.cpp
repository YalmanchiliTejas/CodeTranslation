#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define INF 1LL << 61
#define MAX 1LL << 30
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};

signed main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    while(true){
        int N;
        cin>>N;
        if(N==0) return 0;
        vector<int> V(N);
        for(int i=0;i<N;i++) cin>>V[i];
        sort(V.begin(),V.end());
        int sum=0;
        for(int i=1;i<N-1;i++) sum+=V[i];
        cout<<sum/(N-2)<<endl;
    }
}

