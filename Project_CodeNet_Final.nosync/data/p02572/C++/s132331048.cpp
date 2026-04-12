#include <bits/stdc++.h>
using namespace std;
#define M ((int)1e9+7)
int main() {
    // your code goes here
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long ans=0,sum=0;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	ans+=(a[i]*sum)%M;
    	ans%=M;
    	sum+=a[i];sum%=M;
    }
    cout<<ans;
    return 0;
}