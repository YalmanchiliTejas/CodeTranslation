// BlessRNG
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "file"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

int main()
{
//    freopen(FILE".in", "r", stdin);
//    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if((n % 2 && i % 2) || (n % 2 == 0 && i % 2 == 0))
            dq.push_back(a);
        else
            dq.push_front(a);
    }
    for(int i: dq)
        cout << i << " ";
    return 0;
}
