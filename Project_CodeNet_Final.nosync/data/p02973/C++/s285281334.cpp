#include <bits/stdc++.h>

#define task "E" // ABC134
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

// Limit

// Struct

// Variables
int n,a[100005];
multiset<int> s;
// Function

int main()
{
	//freopen(task".in","r",stdin);
	//freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n)
	{
	    multiset<int>::iterator it=s.lower_bound(a[i]);
	    if (it==s.begin()) s.insert(a[i]);
	    else
        {
            it--;
            s.erase(it);
            s.insert(a[i]);
        }
	}
	cout << s.size();
}
