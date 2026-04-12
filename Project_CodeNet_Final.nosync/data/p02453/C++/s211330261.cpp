#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repd(i,a,b) for (int i = (a); i < (b); i++)
typedef long long ll;

int main(void)
{
	int n, a, q, k;
	cin >> n;
	vector<int> A;
	rep(i, n)
	{
	    cin >> a;
		A.push_back(a);
	}

    cin >> q;
    rep(i, q)
    {
        cin >> k;
        cout << lower_bound(A.begin(), A.end(), k) - A.begin()  << endl;
    }
}
