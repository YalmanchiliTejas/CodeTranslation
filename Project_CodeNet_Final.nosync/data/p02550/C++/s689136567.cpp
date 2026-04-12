#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
    ll n, x, m;
    cin >> n >> x >> m;

    if(n <= m*1000 || n < (ll)1e8){
        vector<ll>a(n+1);
        a[1] = x;
        for(int i=2;i<=n;i++){
            a[i] = a[i-1]*a[i-1]%m;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += a[i];
        cout << ans << endl;
        return 0;
    }

    vector<ll>A;
    set<ll> st;
    A.push_back(x);
    st.insert(x);
    ll t, sz_A = 1;
    while(1){//高々m回
        t = A[sz_A-1]*A[sz_A-1]%m;
        if(st.find(t) != st.end()) break;
        A.push_back(t);
        st.insert(t);
        sz_A++;
    }

    int i;
    for(i=0;i<sz_A;i++) if(A[i] == t) break;

    int T = sz_A - i;

    ll ans = 0;
    for(int j=0;j<i;j++) ans += A[j];

    ll q = (n-i)/T, r = (n-i)%T;
    ll sum = 0;
    for(int j=i;j<sz_A;j++) sum += A[j];
    sum *= q;
    for(int j=i;j<i+r;j++) sum += A[j];

    ans += sum;

    cout << ans << endl;
}
