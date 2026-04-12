#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PI acos(-1.0)
#define sq(n) ((n)*(n))
#define nl "\n"

using namespace std;
typedef long long ll;

int main() {
    int n, a, i;
    deque<int> d;

    cin >> n;

    cin >> a;
    d.push_back(a);

    for (i = 1; i < n; ++i) {
        cin >> a;
        if (i & 1) d.push_back(a);
            else d.push_front(a);
    }

    if (n % 2 == 0) {
        reverse(d.begin(), d.end());
    }

    deque<int>::iterator it = d.begin();
    cout << *it++;
    while (it != d.end()) cout << " " << *it++;
    cout << nl;

    return 0;
}
