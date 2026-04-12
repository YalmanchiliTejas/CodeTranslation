#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;
	if(x >= 30) cout << "Yes";
	else cout << "No";
	return 0;
}