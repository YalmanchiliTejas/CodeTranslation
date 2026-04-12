#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0,l1[51],l2[51],n,k;
void dfs(int j){
	if(j==0){
		k--;
		ans++;
		return;
	}
	k--;
	if(k==0){
		return;
	}
	if(l1[j-1]<=k){
		k-=l1[j-1];
		ans+=l2[j-1];
	}else{
		dfs(j-1);
		return;
	}
	if(k>=1){
		k--;
		ans++;
	}
	if(k==0){
		return;
	}
	if(l1[j-1]<=k){
		k-=l1[j-1];
		ans+=l2[j-1];
	}else{
		dfs(j-1);
		return;
	}
	k--;
}
int main(){
//	freopen("c://a.out","w",stdout);
//	string ham[20];
//	ham[0]="P";
//	for(int i=1;i<=10;i++){
//		ham[i]="B"+ham[i-1]+"P"+ham[i-1]+"B";
//		cout<<ham[i]<<endl<<endl;
//	}
	cin>>n>>k;
	l1[0]=1;
	l2[0]=1;
	for(int i=1;i<=n;i++){
		l1[i]=l1[i-1]*2+3;
		l2[i]=l2[i-1]*2+1;
	}
	dfs(n);
	cout<<ans;
	return 0;
}