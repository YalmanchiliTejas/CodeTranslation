
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
#include<set>
#include<map>
#include <unordered_map>
#include <unordered_set>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include<math.h>
#include <strings.h>



#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

//const int N = 300002;


int n,k;
int main(){
    
    scanf("%d%d",&n,&k);
    
    ll ans = 0;
    lp(i, k+1, n) {
        int j;
        for(j = i; j <= n ; j += i)
            ans += j - (j-i+k) - !(j-i+k);
        if(n < j-i+k) continue;
        if(n%i)
            ans += n - (j-i+k) + 1 - !(j-i+k);
        else ans += !k;
    }
    
    printf("%lld\n",ans);
    return 0;
}



/*

 5 3
 1 3
 1 5
 3 6
 4 4
 2 6
 1 5 3
 1 5 4
 1 1 1

 */
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
//ios::sync_with_stdio(0);cin.tie(0);