#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
ll A[100005];

ll sum(int a, int b) {
    ll res = 0;
    for(int i=a;i<b;++i)res += A[i];
    return res;
}

int main() {
    
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    sort(A, A+N);

    if(N%2==0) {
        ll ans;

        ans = 2*sum(N/2+1, N) + A[N/2];
        ans -= 2*sum(0, N/2-1) + A[N/2-1];

        cout << ans << endl;
    }else {
        ll lsl;

        lsl = 2*sum(N/2+2, N) + A[N/2+1] + A[N/2];
        lsl -= 2*sum(0, N/2);

        ll sls;

        sls = 2*sum(N/2+1, N);
        sls -= 2*sum(0, N/2-1) + A[N/2-1] + A[N/2];

        if(lsl>sls)cout << lsl << endl;
        else cout << sls << endl;
    }

	return 0;
}