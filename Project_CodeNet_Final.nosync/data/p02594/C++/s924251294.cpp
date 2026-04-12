#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ll,ll> pll;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    clock_t ck;
    ck = clock();
    cin >> n;
    cout << (n >= 30 ? "Yes" : "No") << '\n';
    ck = clock()-ck;
    cerr << "It took " << 1.0*ck/CLOCKS_PER_SEC << " sec\n";
    return 0;
}