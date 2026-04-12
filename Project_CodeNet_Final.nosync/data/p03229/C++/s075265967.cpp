#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    sort(all(A));
    ll ans = 0;
    ll left = 0;
    ll right = N - 1;
    if (N % 2 == 0){
        ans += (A[right] - A[left]);
        for (ll i = 1; i < N / 2; i++){
            ans += (A[right] - A[left + 1]);
            ans += (A[right - 1] - A[left]);
            left++;
            right--;
        }
    }
    else{
        ans += (A[right] - A[left]);
        for (ll i = 1; i < N / 2; i++){
            ans += (A[right] - A[left + 1]);
            ans += (A[right - 1] - A[left]);
            left++;
            right--;
        }
        ans += (max(A[N / 2] - A[N / 2 - 1], A[N / 2 + 1] - A[N / 2]));
    }
    cout << ans << endl;
}