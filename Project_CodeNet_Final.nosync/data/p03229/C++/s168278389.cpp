#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A, B, C;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    if(N%2==1) {
        for(int i=0;i<(N-1)/2;i++) {
            B.push_back(-2);
        }
        B.push_back(1);
        B.push_back(1);
        for(int i=0;i<(N-3)/2;i++) {
            B.push_back(2);
        }
        for(int i=0;i<N;i++) {
            ans += A[i]*B[i]; 
        }
        for(int i=0;i<(N-3)/2;i++) {
            C.push_back(-2);
        }
        C.push_back(-1);
        C.push_back(-1);
        for(int i=0;i<(N-1)/2;i++) {
            C.push_back(2);
        }
        for(int i=0;i<N;i++) tmp += A[i]*C[i];
        //cout << tmp << " " << ans << endl;
        ans = max(ans, tmp);
    }
    else {
        for(int i=0;i<N/2-1;i++) {
            B.push_back(-2);
        }
        B.push_back(-1);
        B.push_back(1);
        for(int i=0;i<N/2-1;i++) {
            B.push_back(2);
        }
        for(int i=0;i<N;i++) ans += A[i]*B[i]; 
    }
    cout << ans << endl;
    return 0;
}