#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	long long n;
	cin >> n;
	int a, m;
	cin >> a >> m;
	vector<int> v;
	v.push_back(a);
	vector<int> cnt(N);
	cnt[a] = 1;
	long long sol = 0;
	do
	{
		long long new_a = (v.back() * 1ll * v.back()) % m;
		v.push_back(new_a);
		cnt[new_a]++;
	}while(cnt[v.back()] <= 1);
	int i = 0;
	while(n and cnt[v[i]] == 1)
	{
		sol += v[i++];
		n--;
	}
	int junction = i;
	long long temp = v[i];
	int ct = 1;
	i++;
	while(cnt[v[i]] != 2)
	{
		ct++;
		temp += v[i++];
	}
	sol += n / ct * 1ll * temp;
	n -= n / ct * 1ll * ct;
	while(n)
	{
		sol += v[junction++];
		n--;
	}
	cout << sol;
	
	return 0;
}
