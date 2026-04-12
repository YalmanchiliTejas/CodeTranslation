#include<bits/stdc++.h>
using namespace std;
const int mxn=105;
bool ok[mxn],bok[mxn];
int main(){
	int n,m;
	cin>>n>>m;
	char c[n][m];
	memset(ok,1,sizeof(ok));
	memset(bok,1,sizeof(bok));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
			if(c[i][j]=='#'){
				ok[i]=0;
				bok[j]=0;
			}
		}
	}
	//cout<<endl;
	for(int i=0;i<n;i++){
		if(!ok[i]){
		for(int j=0;j<m;j++){
			if(!bok[j])cout<<c[i][j];
		}
		cout<<endl;
	}

	}

}
//solved  problems for today:1
