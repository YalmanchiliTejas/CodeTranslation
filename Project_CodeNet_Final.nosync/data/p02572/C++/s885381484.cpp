#include<bits/stdc++.h>
#define MAXN 300005
typedef long long ll;
using namespace std;

int n;
ll p = 1e9 + 7,a[MAXN],sum[MAXN],ans = 0;

int main(){
	
	cin>>n;
	for(int i = 1 ; i <= n ; i++)cin>>a[i];
	for(int i = n ; i >= 1 ; i--)sum[i] = (sum[i + 1] + a[i]) % p;
	for(int i = 1 ; i <= n ; i++){
		ans = (ans + a[i] * sum[i + 1]) % p;
	}
	cout<<ans<<endl;
}