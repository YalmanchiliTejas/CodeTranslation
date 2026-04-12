#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int,int> tA;
typedef pair<int,int> tB; // or null_type if you want a set
typedef tree<tA, null_type, less<tA>, rb_tree_tag, tree_order_statistics_node_update> ord_set;
int v[200005];
int main()
{
	ord_set s;
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		scanf("%d",&a);
		v[i] = a;
		s.insert({a,i});
	}
	int idx = n/2-1;
	for(int i = 0 ; i < n ; i++)
	{
	 	auto it = s.lower_bound({v[i],i});
		int val = it->first;
//		cout << "tirando: " << it->first << ' ' << it->second << endl;
		s.erase(it);
		it = s.find_by_order(idx);
		cout << it->first << endl;
		s.insert({val,i});	
	}
	return 0;
}
