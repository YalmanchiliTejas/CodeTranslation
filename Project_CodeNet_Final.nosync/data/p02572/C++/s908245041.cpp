#include <bits/stdc++.h>
#define mdsaqib std::ios::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define all(c) (c).begin(),(c).end()
#define endl '\n'
using namespace std;

int mod=1e9+7;

signed main(){
    mdsaqib;
    int n;
    cin >> n;
    vector <int> A(n),P(n);
    int sum=0;
    for(int i=0;i<n;i++){
        P[i]=sum;
        cin >> A[i];
        sum+=A[i];
        sum%=mod;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=P[i]*A[i];
        ans%=mod;
    }
    cout << ans;
}