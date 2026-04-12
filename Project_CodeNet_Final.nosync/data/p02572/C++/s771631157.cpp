#include<iostream>
#include<algorithm>
#define maxn 200005
using namespace std;
typedef long long ll;
ll n,a[maxn],s[maxn];
ll ans,res;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	ans = 0;
	
	s[1] = a[1];
	for(int i=2;i<=n;i++){
		s[i] = s[i-1] + a[i];
		s[i] %= 1000000007;
	}
	for(int i=2;i<=n;i++){
		ans = (ans+a[i] * s[i-1])%1000000007; 
	}
	cout<<ans<<endl;
	return 0;
}