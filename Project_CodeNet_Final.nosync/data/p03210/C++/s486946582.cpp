#include <bits/stdc++.h>
using namespace std;

#define FOR(i, s, e)   for(int i = (s); i < (e); i++)
#define FOR64(i, s, e) for(ll  i = (s); i < (e); i++)
#define ALL(x)         (x).begin(), (x).end()
#define SORT(b, e)     sort((b), (e))
#define REV(b, e)      reverse((b), (e))
#define VSORT(v)       sort((v).begin(), (v).end())
#define VREV(v)        reverse((v).begin(), (v).end())
#define pb(a)          push_back(a)
#define INF            999999999

typedef long long ll;

int main()
{
	int X;
	cin >> X;

	if(X == 3 || X == 5 || X == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

