#include <bits/stdc++.h>
using namespace std;


int main(){
    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < N; i++) {
        multiset<int>::iterator it = s.upper_bound(-A[i]);
        if (it != s.end()) {
            s.erase(it);
            s.insert(-A[i]);
        } else {
            ans++;
            s.insert(-A[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
