#include <bits/stdc++.h>

using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define f first
#define s second
#define db long double
#define pb push_back
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <iii> viii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 3e3+5;
const db eps = 1e-13;

ll memo[MAX][MAX] , v[MAX];


ll dp ( int lo , int hi ) {

    if( hi==lo )
        return v[lo];

    ll &res = memo[lo][hi];

    if( res != -1 )
        return res;

    return res = max( v[lo]-dp(lo+1,hi) , v[hi]-dp(lo,hi-1) );
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cout<<setprecision(11)<<fixed;
    memset( memo , -1 , sizeof memo );
    int n;cin>>n;
    for( int i = 1; i <= n ; i++ ) {
        cin>>v[i];
        v[i];
    }

    cout<<dp( 1, n )<<"\n";

}

