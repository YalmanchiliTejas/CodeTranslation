#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> A;
    for(int i=1; i<=N; ++i) {
        int a; cin >> a;
        if(i % 2 == N % 2) A.push_front(a);
        else A.push_back(a);
    }
    for(int i=0; i<N; ++i) cout << A[i] << (i==N-1 ? '\n' : ' ');
}