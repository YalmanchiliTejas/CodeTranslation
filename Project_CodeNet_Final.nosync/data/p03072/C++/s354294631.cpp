#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <math.h>
#include <time.h>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <int,int>
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

int main()
{
	int n, A[N];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	int ans = 1; 
	for (int i = 1; i < n; ++i)
	{
		bool ok = true;	
		for (int j = i - 1; j >= 0; --j)
		{
			if(A[j] > A[i])
			{
				ok = false;
				break;
			}
		}
		if(ok)
			ans++;
	}
	cout << ans;	
}

