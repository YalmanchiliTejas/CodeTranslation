#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    deque<int> pile;
    rep(i, N) {
        int a;
        cin >> a;
        if (i == 0)
            pile.push_back(a);
        else {
            int k = lower_bound(all(pile), a) - pile.begin() - 1;
            if (k == -1)
                pile.push_front(a);
            else
                pile[k] = a;
        }
    }

    cout << pile.size() << endl;
}