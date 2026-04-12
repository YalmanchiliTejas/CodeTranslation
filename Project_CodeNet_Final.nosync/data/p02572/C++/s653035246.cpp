#include <bits/stdc++.h>
#define ll long long int
#define K 1000000007
using namespace std;

ll a[200001];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)cin>>a[i], sum=(sum+a[i])%K;
    
    ll ans=0;
    for(int i=0;i<n;i++)
        sum=(sum-a[i]+K)%K , ans=(ans+ (a[i]*sum)%K)%K;
    
    cout<<ans<<endl;
    
    
    
	return 0;
}
