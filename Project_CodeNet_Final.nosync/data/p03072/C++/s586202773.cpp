#include<bits/stdc++.h>
#define n 500000
#define mem(arr) memset(arr, 0, sizeof(arr))
using namespace std;
typedef long long lli;
typedef double llf;
typedef pair<int, int> P;
void solve();
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int times = 1;
//	cin >> times;
	for(int i=0; i<times; i++)
	{
		solve();
		cout << '\n';
	}
	return 0;
}

int a, b, c, d, e, f, g, h;
int arr[n + 50], arr1[n + 50], arr2[n + 50];

//type here

void solve()
{
	cin >> a;
	int mi = 0, cnt = 0;
	for(int i=0; i<a; i++)
	{
		int tmp; cin >> tmp;
		if(tmp >= mi)
		{
			mi = tmp;
			cnt ++;
		}
	}
	cout << cnt;
}