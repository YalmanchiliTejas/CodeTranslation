//----------ACCIDENTAL COMPETITIVE PROGRAMMER---------------------

#include<bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
using namespace std;

#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair


const LL MOD = (1e9) + 7 ;
const LD EPS = 0.0000001 ;

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n; cin >> n;
   LL arr[n];
   for (int i = 0; i < n; i++){
   		cin >> arr[i];
   }
   int ans = 1;
   LL mx = arr[0];
   for (int i = 1; i < n; i++){
   		if (arr[i] >= mx){
   			ans++;
   		}
   		mx = max (mx, arr[i]);
   }
   cout << ans << endl;
	return 0;
}