#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define rall(c) c.end(), c.begin()
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pi;
typedef map<int, int> MPII;
typedef set<int> SETI;

const int mxN = 2e5;
int a[mxN];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    s[0] == s[2] ? cout << "No" : cout << "Yes";

    return 0;
}