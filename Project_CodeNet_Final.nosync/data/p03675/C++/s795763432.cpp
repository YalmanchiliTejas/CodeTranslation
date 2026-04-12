#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int>   vi;
typedef vector<long long> vll;
typedef vector<pair<int,int> > vii;
#define ll long long
#define pb push_back
#define mp  make_pair
#define ff first
#define ss second
#define pq priority_queue
#define sf(x) scanf("%d",&x)
int inf = (1e9) + 7;


int main(){
	int n;
	cin >> n;



	vi v;
	int aux;
	for (int i = 0; i < n; ++i)
	{
		sf(aux);
		v.pb(aux);		
	}


	vi ans;

	if(n%2)
	{
		for (int i = n-1; i >= 0; i-=2)
		{
			ans.pb(v[i]);
		}
		for (int i = 1; i < n; i+=2)
		{
			ans.pb(v[i]);
		}
	}
	else
	{
		for (int i = n-1; i >= 0; i-=2)
		{
			ans.pb(v[i]);
		}
		for (int i = 0; i < n; i+=2)
		{
			ans.pb(v[i]);
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d ",ans[i] );
	}
	printf("\n");
}