//Use valgrind once if the submission doesn't go through. It can detect uninitialized variables and see where they could be an issue.
#include <bits/stdc++.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007;
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);

	long long n,s{0};
	cin>>n;
	vector<long long> a(n),prefix(n+1,0);
	for(int i=0;i<a.size();++i){
		cin>>a[i];
		prefix[i+1]=prefix[i]+a[i];
		prefix[i+1]%=MOD;
		s+=prefix[i]*a[i];
		s%=MOD;
	}
	cout<<s<<endl;
}
