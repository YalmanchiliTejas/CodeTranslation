#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll N;
	ll num;
	ll time=0;
	ll i,j;
	//pair<ll,ll> H[50];
	ll H[50];
	cin>>N;
	for(ll i=0;i<N;i++){
		cin>>H[i];//=make_pair(num,i);
	}
	num=0;
	for(i=0;i<N;i++){
		for(j=0;j<i;j++){
			if(H[i]>=H[j]) num++;
		}
		if(num==i) time++;
		num=0;
	}
	cout<<time<<endl;
}