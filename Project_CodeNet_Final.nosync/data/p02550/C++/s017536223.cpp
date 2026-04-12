#pragma GCC optimize("O2")
#include<bits/stdc++.h>
typedef long long ll ;
#define pll pair<ll , ll >
#define X   first
#define Y   second
#define mp  make_pair
#define pii pair<int , int>
#define vec vector
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int maxn = 1000*1000+5 ;
const ll inf = 9223372036854775807 ;
const ll mod = 1e9 + 7 ;
ll ps[maxn] , n , m , x  , a[maxn] , mark[maxn] , ans  ;  
int main()
{
	migmig ;
	cin>>n>>x>>m ; 
	a[1] = x ; 
	ps[1] = x;
	for(int i = 2 ; i <= 25 * ( m + 1 ) ; i ++ )
	{
		a[i] = (a[i-1] * a[i-1]) % m ; 
		ps[i] = ps[i-1] + a[i] ; 
		if(mark[a[i]])
		{
			ll j = mark[a[i]] ; 
			ans += ps[j-1] ; 
			n -= (j - 1) ; 
			ans += n / (i - j) * (ps[i-1] - ps[j-1]) ; 
			ans += ps[j + n % (i - j) - 1] - ps[j-1] ; 
			cout<<ans ; 
			return 0 ;
 		}
 		mark[a[i]] = i ; 
 		if(i == n)
 		{
 			cout<<ps[i] ; 
 			return 0 ; 
		 }
	}
}






