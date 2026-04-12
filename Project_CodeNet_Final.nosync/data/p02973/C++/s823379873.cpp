#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    deque<int> d;
    rep(i,N){
        int p = lower_bound(all(d),A[i]) - d.begin();
        if(p==0) d.push_front(A[i]);
        else d[p-1] = A[i];
    }
    cout << d.size() << endl;
}