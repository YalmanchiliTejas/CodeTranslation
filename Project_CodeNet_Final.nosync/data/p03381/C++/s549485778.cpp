#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/tree_policy.hpp>   // Contains class "tree_order_statistics_node_update".
using namespace std;
using namespace __gnu_pbds;   // Appropriate namespace (called "pb_ds" earlier).

typedef tree<
             pair<int,int>,         // type of data (value) inside ordered set
             null_type,
             less<pair<int,int> >,   // should be the same type as value (!), also you can use "greater<int>" here for descending order of sort
             rb_tree_tag,
             tree_order_statistics_node_update
            > ordered_set;

int const MAX_N = 256*1024;
int s[MAX_N];

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&s[i]);
    ordered_set X;
	for (int i=0; i<n; i++) X.insert(make_pair(s[i],i));
	int l = n-1;
	for (int i=0; i<n; i++) {
		X.erase(make_pair(s[i],i));
		printf("%d\n",X.find_by_order((l+1)/2-1)->first);
		X.insert(make_pair(s[i],i));
	}
    return 0;
}