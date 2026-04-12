#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int MAXN = 100500;

int main()
{                                                     
	ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        ok |= s.substr(i, 2) == "AC";
    }

    cout << (ok ? "Yes\n" : "No\n");
	
	return 0;
}
