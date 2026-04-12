#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main() {
    lint N; cin >> N;
    vector<lint> A(N); 
		for(lint i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    lint ans;
    if(N % 2 == 0){
        lint temp=0;
        for(lint i = 0; i < N/2-1; i++) temp -= 2*A[i];
        temp -= A[N/2-1];
        temp += A[N/2];
        for(int i = N/2 + 1; i < N; i++)  temp += 2 * A[i];
        ans = temp;
    }
    else {
        lint temp = 0;
        for(lint i = 0; i < N/2-1; i++) temp -= 2*A[i];
        for(lint i = N/2+2; i < N; i++) temp += 2*A[i];
        ans = max( temp - 2*A[N/2-1] + A[N/2] + A[N/2+1], temp - A[N/2-1] - A[N/2] + 2*A[N/2+1] );
    }
    cout << ans << endl;
}