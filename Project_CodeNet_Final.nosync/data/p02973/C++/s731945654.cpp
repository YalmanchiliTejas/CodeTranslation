#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>

int main() {

    int N;
    cin >> N;

    vp A;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(make_pair(-a, i));
    }

    set<pii> s;
    for (int i = 0; i < N; i++) {
        auto itr = s.upper_bound(A[i]);
        if (itr != s.end()) {
            s.erase(itr);
        }
        s.insert(A[i]);
    }

    cout << s.size() << endl;

    return 0;
}
