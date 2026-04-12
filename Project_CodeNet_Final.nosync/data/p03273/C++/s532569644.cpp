#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
	ll n,m,i,j,k,flag=0;
	cin>>n>>m;
	char ch[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>ch[i][j];
		}
	}
	vector<ll> vir,vic;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<m;j++){
			if(ch[i][j]=='#'){
				flag=1;
			}
		}
		if(flag==0){
			vir.pb(i);
		}
	}
	for(j=0;j<m;j++){
		flag=0;
		for(i=0;i<n;i++){
			if(ch[i][j]=='#'){
				flag=1;
			}
		}
		if(flag==0){
			vic.pb(j);
		}
	}
	for(i=0;i<n;i++){
		ll count=0;
		for(j=0;j<m;j++){
			flag=0;
			for(k=0;k<vir.size();k++){
				if(vir[k]==i){
					flag=1;
				}
			}
			for(k=0;k<vic.size();k++){
				if(vic[k]==j){
					flag=1;
				}
			}
			if(flag==0){
				cout<<ch[i][j];
				count=1;
			}
		}
		if(count==1){
			cout<<endl;
		}
	}
}  