#include<bits/stdc++.h>
using namespace std;
int dl[300000]={};//左から
int dr[300000]={};//右から
int n;

bool cdl(int s){
	bool ans=0;
	if(s==n-1) return true;
	for(int i=1; i<=dl[s]/10; i++){
		if(cdl(s+i)){
			ans=true;
			break;
		}
	}
	dl[s]=0;
	return ans;
}

bool cdr(int s){
	bool ans=0;
	if(s==n-1) return true;
	for(int i=1; i<=dr[s]/10; i++){
		if(cdr(s+i)){
			ans=true;
			break;
		}
	}
	dr[s]=0;
	return ans;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		dl[i]=a;
		dr[n-1-i]=a;
	}
	if(cdr(0) && cdl(0)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
