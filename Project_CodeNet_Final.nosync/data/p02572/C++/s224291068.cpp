#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int m= 1000000007;
void testcase(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll ans=0;
    vector <ll> sum;
    sum.push_back(a[n-1]);
    for(int i=n-2;i>0;i--){
        sum.push_back((sum.back()+a[i])%m);
    }
    for(int i=n-2;i>=0;i--){
        ans+= a[i]*sum[n-2-i];
        ans%=m;
    }
    cout << ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1;
  //  cin >> q;
    while(q--){
    testcase();
    }
    return 0;
}

