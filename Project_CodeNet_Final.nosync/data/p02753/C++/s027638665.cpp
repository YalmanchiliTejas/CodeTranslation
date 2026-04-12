#include <bits/stdc++.h>
#include <math.h>

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;

void solve()
{   
    string s;
    cin >> s;

    sort(all(s));

    cout << (s[0] == s[2] ? "No" : "Yes") << '\n';
} 

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

    // int t; cin >> t; while (t--)
    solve();

    return 0;
}