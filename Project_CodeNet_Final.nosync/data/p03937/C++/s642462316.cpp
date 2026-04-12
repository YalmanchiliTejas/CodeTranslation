#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	string s[10];
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	int f=0,jj=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='#'){
				if(j<jj) f=1;
				jj=j;
			}
			if(f) break;
		}
		if(f) break;
	}
	if(f) cout<<"Impossible"<<endl;
	else {
		cout<<"Possible"<<endl;
	}
	
	return 0;
}
