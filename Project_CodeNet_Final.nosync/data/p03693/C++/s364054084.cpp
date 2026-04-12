#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int r,g,b; cin >> r >> g >> b;
	int n = (r*100) + (g*10) + b;
	if (n % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}