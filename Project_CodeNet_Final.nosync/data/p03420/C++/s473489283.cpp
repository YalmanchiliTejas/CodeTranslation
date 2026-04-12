#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=k+1;i<=n;i++){
	ans+=(i-k)*(n/i);
	ans+=max((ll)0,n%i-(k-1));
	//cout<<"#"<<ans<<endl;
    }
    if(k==0)ans-=n;
    cout<<ans<<endl;
    return 0;
}
