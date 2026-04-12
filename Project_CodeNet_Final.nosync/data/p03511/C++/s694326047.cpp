#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 20;
 
int n;
string s, t;
int ans = 0, ss = s.size(), tt = t.size(), boz;

bool cmp (string s, string t)
{
	string v1, v2;
	for ( ; v1.size() <= 1000000; ) v1 += s;
	for ( ; v2.size() <= 1000000; ) v2 += t;
	return v1 > v2;
}
	
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> t;
	ss = s.size(), tt = t.size();
	if (cmp (s, t))
		swap (s, t), swap (ss, tt);
 
	for (int i = 0; i * ss <= n; i++)
		if ( (n - i * ss) % tt == 0)
			ans = i, boz = (boz == -1 ? i : boz);
	string res1, res2;
	
	for (int i = 0; i < ans; i++)
		cout << s;	
	n -= ss * ans;
	for (int i = 0; i * tt < n; i++)
		cout << t;
	cout << endl;
	return 0;
}