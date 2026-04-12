#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int ans[100005];
int last[100005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, m;
	cin>>n>>x>>m;
	ans[1]=x;
	last[x]=1;
	int ind1=-1;
	int ind2=-1;
	
	for(int i=2; i<=100004; i++){
		ans[i]=(ans[i-1]*ans[i-1])%m;
		if(last[ans[i]]!=0){
			ind1=last[ans[i]];
			ind2=i;
			break;
		}
		last[ans[i]]=i;
	}
	for(int i=2; i<=100004; i++){
		ans[i]=(ans[i-1]*ans[i-1])%m;
	}
	int ans1=0;
	for(int i=1; i<ind1; i++){
		ans1+=ans[i];
	}
	
	if(n<ind1){
		int ans2=0;
		for(int i=1; i<=n; i++){
			ans2+=ans[i];
		}
		cout<<ans2;
		return 0;
	}
	int ans2=0;
	for(int i=ind1; i<ind2; i++){
		ans2+=ans[i];
	}
	
	
	int cyc=(n-ind1+1)/(ind2-ind1);
	int rem=(n-ind1+1)%(ind2-ind1);
	int val=ans[ind1];
	
	int ans3=0;
	while(rem!=0){
		rem--;
		ans3+=val;
		val=(val*val)%m;
	
	}
	cout<<ans1+cyc*ans2+ans3;
	return 0;
}