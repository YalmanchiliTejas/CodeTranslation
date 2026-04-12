#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define mp make_pair
#define EPS (int)1e-9
#define PI acos(-1)
#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1000000007;

map<char, int> toFreqMap(string &s)
{
	map<char, int> freq;
	int n = s.size();

	for(int i = 0; i < n; i++)
		freq[s[i]]++;

	return freq;
}

map<char, int> intersect(map<char, int>&a, map<char, int>&b)
{
	map<char, int> ans;

	for(pair<char, int> x: a)
	{
		if(b.find(x.fi) != b.end())
			ans[x.fi] = min(x.se, b[x.fi]);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s = "";
	cin >> s;

	map<char,int> ans, aux;
	ans = toFreqMap(s);

	for(int i = 1; i < n; i++)
	{
		s = "";
		cin >> s;
		aux = toFreqMap(s);
		ans = intersect(ans, aux);
	}

	if(!ans.empty())
		for(pair<char, int> x: ans)
			cout << string(x.se, x.fi);

	cout << endl;

	return 0;	
}