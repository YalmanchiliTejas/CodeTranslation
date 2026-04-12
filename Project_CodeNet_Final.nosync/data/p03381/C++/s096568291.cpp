#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > A;
vector<int> R;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        A.push_back({v, i});
    }
    sort(A.begin(), A.end());
    int off = n / 2;
    R = vector<int> (n);
    for(int i = 0; i < n; i++) {
        R[A[i].second] = A[i + off].first;
        off--;
        if(off == 0) off--;
    }
    for(int i : R) cout << i << endl;
}
