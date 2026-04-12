#include <bits/stdc++.h>
using namespace std;

int L;
string s, t;

int main() {
	cin >> L >> s >> t;
	
	if (s + t > t + s)
		swap(s, t);
	
	int N = s.size(), M = t.size();
	int mx = 0;
	for (int i = 0; i <= L / N; i++)
		if (!((L - i * N) % M))
			mx = i;
	
	string sol = "";
	for (int i = 0; i < mx; i++)
		sol += s;
	for (int i = 0; i < (L - mx * N) / M; i++)
		sol += t;
	
	cout << sol << endl;
	
	return 0;
}