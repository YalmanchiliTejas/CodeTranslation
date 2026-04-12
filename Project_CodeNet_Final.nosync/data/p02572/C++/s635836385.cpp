#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define M 1000000007
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int N = 2e5 + 1;
int ad(ll a , ll b){
	return(a + b)%M;
}
int mult(ll a , ll b){
	return(a*b)%M;
}
int cs[N] , a[N] , n;
int main(){
	cin >> n;
	for (int i = 0; i < n; ++i){
		scanf("%d",a+i);
	}
	for (int i = n-1; i >= 0; --i){
		cs[i] = ad(cs[i+1] , a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans = ad(ans , mult(a[i] , cs[i+1]));
	}
	printf("%d\n",ans);
}	