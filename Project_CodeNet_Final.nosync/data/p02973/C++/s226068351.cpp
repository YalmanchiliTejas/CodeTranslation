#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, /*count=1,*/ f=0, min = 1000000001;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    deque<int> d;
    
    for(int i=0; i<N; i++) {
        int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
        if(!p) d.push_front(A[i]);
        else d[p-1] = A[i];
    }

    cout << d.size() << endl;

    return 0;

}