#include <bits/stdc++.h>
#define ll long long int
#define ld double
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
int main()
{
	boost;
	int n, i;
	cin >> n;
	int arr[n];
	fo(i, 0, n)
	cin >> arr[i];
	int mx = -1;
	int ans = 0;
	fo(i, 0, n){
		if(arr[i] >= mx)
		ans++;
		mx = max(mx, arr[i]);
	}
	cout << ans;
}