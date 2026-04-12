/*
ID: 5ak0
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define mpr make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

int n, x;
deque <int> b;

int main(){
    #ifndef SAKO
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    #endif // SAKO
    ios_base::sync_with_stdio(0);


	cin >> n;
	for (int i = 1; i <= n; ++i){
        cin >> x;
        if (i % 2 == 1)
            b.push_front(x);
        else
            b.pb(x);
	}
	if (n % 2 == 1)
        for (int i = 0; i < b.size(); ++i)
            cout << b[i] << " ";
    else
        for (int i = b.size() - 1; i >= 0; --i)
            cout << b[i] << " ";
    return 0;
}
