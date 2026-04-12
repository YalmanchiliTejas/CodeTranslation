#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;

#define fbo find_by_order
#define ook order_of_key
#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

// /mnt/c/Users/vince/Desktop/POST-IOI/  

long n, x, m;
vector<long> vec;
int visited[100003];

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	scanf("%lld %lld %lld", &n, &x, &m);
	long a = x;
	while(1)
	{
		visited[a] = vec.size();
		vec.push_back(a);
		a = (a*a)%m;
		if(visited[a])
		{
			// printf("%lld\n", a);
			break;
		}
	}
	int sz1 = 0, sz2 = vec.size();
	long sum = 0;
	for(int i = visited[a]; i < vec.size(); i++)
	{
		sz2--;
		sz1++;
		sum += vec[i];
	}
	// printf("%lld\n", sum);
	// for(auto x : vec) printf("%lld ", x); printf("\n");

	long res = 0;
	if(n <= sz2)
	{
		for(int i = 0; i < n; i++)
			res += vec[i];
	}
	else
	{
		for(int i = 0; i < sz2; i++)
			res += vec[i];
		n -= sz2;
		
		res += sum*(n/sz1);
		n %= sz1;
		for(int i = 0; i < n; i++)
			res += vec[visited[a]+i];
	}
	printf("%lld\n", res);
}