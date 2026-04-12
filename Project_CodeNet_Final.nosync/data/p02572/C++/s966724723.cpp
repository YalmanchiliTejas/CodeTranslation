#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PI 3.1415926535897932384626433
#define ceil1(a,b)   (a+(b-1))/b
#define all(v)  v.begin(),v.end()
#define gen(arr,n,nxt)  generate(arr,arr+n,nxt)
#define base ios_base::sync_with_stdio(false);cin.tie(0);
#define open freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
const int mo=1e9+7;
int nxt(){int x;cin>>x;return x;}
int mod(int n,int m){int ans=n%m;if(ans<0)ans+=m;return ans;}
int32_t main(){
    base
    int n=nxt();
    int arr[n];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cnt+=arr[i];
        cnt=mod(cnt,mo);
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        cnt-=arr[i];
        cnt=mod(cnt,mo);
        ans+=arr[i]*cnt;
        ans=mod(ans,mo);
    }
    cout<<ans<<endl;
    return 0;
}
