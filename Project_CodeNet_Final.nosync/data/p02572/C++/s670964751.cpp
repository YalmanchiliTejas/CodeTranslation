/*Q-3---ATCODER-BEGINNER-#ROUND_177

*/

#include <bits/stdc++.h>
#define M 1000000007
#define endl '\n'
#define ll long long
using namespace std;

ll mod(ll x){ return ((x%M + M)%M);}
ll add(ll a,ll b){ return mod(mod(a)+mod(b));}
ll mul(ll a,ll b){ return mod(mod(a)*mod(b));}
ll sub(ll a,ll b){ return mod(mod(a)-mod(b));}
ll divide(ll a,ll b){ return mod(mod(a)/mod(b));}

ll findProductSum(ll arr[],ll n){ 
    ll sum{0};
    for(ll i=0;i<n;i++)
        sum=add(sum,arr[i]);

    ll ans{0};
    for(ll i=0;i<n-1;i++){
        sum=sub(sum,arr[i]);
        ans=add(ans,mul(arr[i],sum));
    }

    return ans;
} 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	ll n{0};
	cin>>n;

	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];

	cout<<(findProductSum(arr,n)%M)<<endl;

	return 0;
}

