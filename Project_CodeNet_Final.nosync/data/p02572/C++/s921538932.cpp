#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e6 + 77 , mod = 1e9+7;
int A[N] , pre[N];

int32_t main(){
    int n ; cin >> n ;
    for(int i = 0 ; i < n ; ++i) cin >> A[i];
    reverse(A,A+n);
    int sum = 0 ;
    for(int i  = 0 ; i <  n ; ++i){
        sum += A[i];
        pre[i] = sum;
    }
    reverse(A,A+n);
    reverse(pre,pre+n);
    
    sum = 0;
    for(int i = 0 ; i < n-1 ;++i) {
        sum += (A[i] * (pre[i+1]%mod))%mod;
        sum = sum % mod;
    }
    cout << sum << endl;
    return 0;
}