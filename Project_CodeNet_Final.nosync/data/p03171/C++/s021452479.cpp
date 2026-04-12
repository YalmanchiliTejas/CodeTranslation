//In the name of Allah
//In the name of the compassionate of the merciful
//Ya Ali!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename Type>
using ordered_multiset = tree<Type, null_type, less_equal<Type>, rb_tree_tag, tree_order_statistics_node_update> ;

typedef long long ll ;
typedef long double ld ;

const ll maxn = 3011 ;
const ll INF = 3e18 ;

#define f first
#define s second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define endll "\n"
#define sortt(v) sort(v.begin() , v.end())
#define reversee(v) reverse(v.begin() , v.end())

// for sqrt on interval and array , always sq = maxn/80 ;
// cout << *ss.find_by_order(index) ; -> return the value that indexed in index position
// cout << ss.order_of_key(value) ; -> lower_bound in ordered_set
//ifstream fin("input.txt");
//ofstream fout("output.txt");
// fflush(stdout);
ll mod = 1e9 + 7 , p1 = 999999929 , p2 = 999999937 ;

ll n , a[maxn] , dp[maxn][maxn][2] ;

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> n ;
for(int i = 1 ; i <= n ; i ++)cin >> a[i] ;

for(int i = 1 ; i <= n ; i ++){
 dp[i][i][0] = a[i] ;
 dp[i][i][1] = (-1)*a[i] ;
}

for(int r = 2 ; r <= n ; r ++){
  for(int l = r-1 ; l > 0 ; l --){
   dp[l][r][0] = max(dp[l+1][r][1]+a[l] , dp[l][r-1][1]+a[r]) ;
   dp[l][r][1] = min(dp[l+1][r][0]-a[l] , dp[l][r-1][0]-a[r]) ;
   //cout << a[l] << " " << l << endl ;
  }
}
cout << dp[1][n][0] ;

 return 0;
}
/*
                  _     _   __
            /_\  (_    (_)  __)
           /   \  _) . (_) (__
*/
