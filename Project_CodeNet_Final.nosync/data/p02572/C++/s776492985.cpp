typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
ll maxl(ll a, ll b){ return ((a<b)?b:a);}
ll minl(ll a, ll b){ return ((a>b)?b:a);}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    int M = 1e9 + 7;
    vector<int> suffix(n,0);
    suffix[n-1] = arr[n-1];
    for (int i=n-2;i>=0;i--){
        ll temp = (ll)(arr[i] + suffix[i+1]);
        temp = temp%M;
        suffix[i] = temp;
    }
    ll ans = 0;
    for (int i=0;i<n-1;i++){
        ll temp = arr[i];
        ll temp2 = suffix[i+1];
        temp = (temp*temp2)%M;
        ans = (ans + temp)%M;
    }
    cout << ans << "\n";
}
