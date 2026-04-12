/*
	LINES :
		* a nice cumulative sum problem
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define OJ
#define pb push_back
#define F first
#define S second
#define WLL(t) while(t--)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define VFOR(i,a,b) for(int i = a; i >= b; i--)
#define ALL(v) v.begin(),v.end()
#define PRECISION(x) cout<<fixed<<setprecision(x)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define MOD 1000000007

void solve(int arr[], int n, ll sum);
int main()
{
#ifndef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	int n{};
	ll sum{};
	cin >> n;
	int arr[n];
	FOR(i, 0, n) {
		cin >> arr[i];
		sum += arr[i];
		sum %= MOD;
	}
	solve(arr, n, sum);
	return 0;
}
void solve(int arr[], int n, ll sum)
{
	//doing cumulative sum
	ll cusum{};
	FOR(i, 0, n) {
		sum -= arr[i];
		if (sum < 0)
		{
			sum += MOD;
		}
		cusum += arr[i] * sum;
		cusum %= MOD;
	}
	cout << cusum << "\n";
}