#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9


int main(){
int n;
cin>>n;
vector<int> h(n);
for(int i=0;i<n;i++)cin>>h[i];
int cnt = 1;
int m = h[0];
for(int i=1;i<n;i++){
	if(m<=h[i]){
		m = h[i];
		cnt++;
	}
}
cout<<cnt<<endl;

	return 0;
}
