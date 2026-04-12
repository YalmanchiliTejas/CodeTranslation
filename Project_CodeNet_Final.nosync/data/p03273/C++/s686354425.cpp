#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	
	ll n,m,i;
	cin>>n>>m;
	
	char a[n][m];
	for(i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	vector <int > r,c;
	for(i=0;i<n;i++){
		ll w=1;
		for(int j=0;j<m;j++){
			if(a[i][j]=='#'){
				w=0;
				break;
			}
		}
		if(w){
			r.push_back(i);
		}
	}
	
	for(int j=0;j<m;j++){
		ll w=1;
		for(i=0;i<n;i++){
			if(a[i][j]=='#'){
				w=0;
				break;
			}
		}
		if(w){
			c.push_back(j);
		}
	}
	ll check[n][m]={};
	
	for(i=0;i<r.size();i++){
		for(int j=0;j<m;j++){
			check[r[i]][j]=1;
		}
	}
	for(i=0;i<n;i++){
		for(int j=0;j<c.size();j++){
			check[i][c[j]]=1;
		}
	}
	
	for(i=0;i<n;i++){
		int flag=1;
		for(int j=0;j<m;j++){
			if(!check[i][j]){
				cout<<a[i][j];
				flag=0;
			}
		}
	//	if(flag)
			cout<<endl;
	}
	
}

