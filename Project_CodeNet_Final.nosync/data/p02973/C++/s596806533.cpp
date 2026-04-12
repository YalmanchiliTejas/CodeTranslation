#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e5+10)
#define MAX (int)(1e5+7)

int N;
int a[max_size];
const int INF = 1e9+7;
int main ()
{
	ios::sync_with_stdio(0);
	cin >> N ;
	vector <int> v;
	v.push_back(0);
	for ( int i = 1 ; i <= N ; i++ )
		cin >> a[i];
	for ( int i = 1 ; i <= N ; i++ )
	{
		if ( v.size() == 1 )
		{
			v.push_back(a[i]);
			continue;
		}
		int left = 1 , right = (int)v.size();
		while ( left < right )
		{
			int mid = left + right >> 1;
			if ( v[mid] < a[i] )
				right = mid;
			else left = mid+1;
		}
		if ( left == (int)v.size() )
			v.push_back(a[i]);
		else v[left] = a[i];
	}
	cout << v.size()-1 << endl;
}