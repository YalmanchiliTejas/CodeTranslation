#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    ll data[n]; rep(i,n) cin >> data[i];
    ll ans[n];

    sort(data,data+n);

    int count = n-1;
    for(int i = 2; i < n; i += 2){
        ans[i] = data[count]; count--;
    }
    ans[0] = data[count]; count = 0;
    for(int i = 1; i < n; i += 2){
        ans[i] = data[count]; count++;
    }
    ll num1= 0;
    rep(i,n-1) num1 += abs(ans[i+1]-ans[i]);

    count = 0;
    for(int i = 2; i < n; i += 2){
        ans[i] = data[count]; count++;
    }
    ans[0] = data[count]; count = n-1;
    for(int i = 1; i < n; i += 2){
        ans[i] = data[count]; count--;
    }
    ll num2= 0;
    rep(i,n-1) num2 += abs(ans[i+1]-ans[i]);

    cout << max(num1,num2) << endl;
}

