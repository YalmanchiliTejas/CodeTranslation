#include<bits/stdc++.h>
using namespace std;
bool b[100],bo[100];
char c[100][100];
int main(){
	int a,d;
	cin>>a>>d;
	for(int i=0;i<a;i++){
		for(int j=0;j<d;j++){
			cin>>c[i][j];
			if(c[i][j]=='#') {
				b[i]=true;
				bo[j]=true;
			}
		}
	}
	for(int i=0;i<a;i++){
		bool boo=false;
		for(int j=0;j<d;j++){
			if(b[i]&&bo[j]){
				cout<<c[i][j];
				boo=true;
			}
		}
		if(boo)puts("");
	}
	return 0;
}
