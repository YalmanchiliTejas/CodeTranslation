#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	ll n,ans=0,ans2=0;
	cin>>n;
	priority_queue<ll> L,L2;
	priority_queue<ll,vector<ll>,greater<ll>> S,S2;
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		L.push(a);
		S.push(a);
		L2.push(a);
		S2.push(a);
	}
	ll a=S.top(),b=S.top();
	S.pop();
	for(int i=0;i<n/2;i++){
		if(i%2==0){
			ans+=abs(L.top()-b);
			b=L.top();
			L.pop();

			ans+=abs(L.top()-a);
			a=L.top();
			L.pop();
		}else{
			ans+=abs(S.top()-a);
			a=S.top();
			S.pop();

			ans+=abs(S.top()-b);
			b=S.top();
			S.pop();
		}
	}
	ll a2=L2.top(),b2=L2.top();
	L2.pop();
	for(int i=0;i<n/2;i++){
		if(i%2==0){
			ans2+=abs(S2.top()-b2);
			b2=S2.top();
			S2.pop();

			ans2+=abs(S2.top()-a2);
			a2=S2.top();
			S2.pop();
		}else{
			ans2+=abs(L2.top()-a2);
			a2=L2.top();
			L2.pop();

			ans2+=abs(L2.top()-b2);
			b2=L2.top();
			L2.pop();
		}
	}
	cout<<max(ans,ans2)<<endl;
	return 0;
}