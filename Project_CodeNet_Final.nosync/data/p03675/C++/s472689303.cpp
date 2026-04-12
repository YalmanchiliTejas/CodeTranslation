#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<math.h>
#include<list>
#include<limits.h>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define PI 3.141592654
#define rep(i,a) for(int i=1;i<=a;i++)
#define loop(j,b) for(int j=0;j<b;j++)
typedef long long ll;
using namespace std;
const int MXSIZE = 1e6+6;
int main(){
ll n;
cin>>n;
vector<ll> a(n+1);
ll t=0,x=0;
for(ll i=1;i<=n;i++){
	cin>>x;
	t=n-i;
	if(t%2==0){
		a[1+(t/2)]=x;
	}
	if(t%2==1){
		t-=1;
		a[n-(t/2)]=x;
	}
	
}
for(ll i=1;i<=n;i++){
	cout<<a[i]<<" ";


}

	return 0;
}