#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define int long long int
const int mod = 1000000007;
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;


signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        sum = sum%mod;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        sum -= arr[i];
        if(sum < 0)
            sum += mod;
        ans += arr[i]*sum;
        ans = ans%mod;
    }
    cout<<ans<<endl;
    return 0;
}