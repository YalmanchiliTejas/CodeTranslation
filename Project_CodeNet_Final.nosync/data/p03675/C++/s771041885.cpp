#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }

    if(N % 2 == 0) {
        for(int i=N-1; i>0; i -= 2) cout << A[i] << ' ';
        for(int i=0; i<=N-2; i += 2) cout << A[i] << (i==N-2 ? '\n' : ' ');
    } else {
        if(N == 1) cout << A[0] << endl;
        else {
            for(int i=N-1; i>=0; i -= 2) cout << A[i] << ' ';
            for(int i=1; i<=N-2; i += 2) cout << A[i] << (i==N-2 ? '\n' : ' ');
        }
    }
}
