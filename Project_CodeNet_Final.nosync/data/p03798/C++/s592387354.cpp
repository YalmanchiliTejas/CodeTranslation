#include<bits/stdc++.h>
using namespace std;

bool a[100010],r[100010];
int n;

void solve(){
	for(int i=1;i<n;i++){
		if(r[i]==1){
			if(a[i]==0) a[i+1]=a[i-1];
			else a[i+1]=1-a[i-1];
		}
		else{
			if(a[i]==0) a[i+1]=1-a[i-1];
			else a[i+1]=a[i-1];
		}
	}
	int x;
	if(r[0]==1){
		if(a[0]==0) x=a[1];
		else x=1-a[1];
	}
	else{
		if(a[0]==0) x=1-a[1];
		else x=a[1];
	}
	if(a[n]==a[0]&&a[n-1]==x){
		for(int i=0;i<n;i++){
			if(a[i]==0) cout<<"S";
			else cout<<"W";
		}
		exit(0);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		if(x=='o') r[i]=1;
		else r[i]=0;
	}
	memset(a,0,sizeof(a));
	a[0]=0;
	a[1]=0;
	solve();
	memset(a,0,sizeof(a));
	a[0]=0;
	a[1]=1;
	solve();
	memset(a,0,sizeof(a));
	a[0]=1;
	a[1]=0;
	solve();
	memset(a,0,sizeof(a));
	a[0]=1;
	a[1]=1;
	solve();
	cout<<"-1"<<endl;
	return 0;
}