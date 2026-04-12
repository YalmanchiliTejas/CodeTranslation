#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <queue>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
#define MOD int(1e9+7)
#define REP(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define fi first
#define se second

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S; cin >> S;
	bool flag = false;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S.substr(i, 2) == "AC")flag = true;
	}

	cout << (flag ? "Yes" : "No") << endl;

    return 0;
}

