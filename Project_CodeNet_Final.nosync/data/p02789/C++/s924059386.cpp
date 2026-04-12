// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define bp __builtin_popcountll
#define MOD  1000000007
const int N = 100005;
 
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    ll m,n;
    cin >> m >>n ;
    if(m==n)    cout<<"Yes";
    else        cout<<"No";
}