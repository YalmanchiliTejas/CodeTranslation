#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;

long long mod(long long x){
        return ((x%M + M)%M);
    }
long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }


int solve(vector <int> arr, int n) {
    vector <ll> pref(n+1);
    for(int i=n-1;i>=0;i--){
        pref[i]=pref[i+1]+arr[i];
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        ans=add(ans,mul(arr[i],pref[i+1]));
    }
    return ans;
   
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("inputcpp.txt", "r", stdin);
        freopen("outputcpp.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector <int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
    
    
}