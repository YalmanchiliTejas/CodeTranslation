#include <bits/stdc++.h>

#define int long long
#define double long double

const int INF=2147483647;
const int MOD=1000000007;
const int mod=998244353;
const double eps=1e-18;

using namespace std;

int arr[200001];
int prefsum[200001];
int res;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    prefsum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefsum[i]=prefsum[i-1]+arr[i];
        prefsum[i]%=MOD;
    }

    res=0;
    for(int i=1;i<n;i++){
        res+=prefsum[i-1]*arr[i];
        res%=MOD;
    }

    cout<<res<<endl;

    return 0;
}
