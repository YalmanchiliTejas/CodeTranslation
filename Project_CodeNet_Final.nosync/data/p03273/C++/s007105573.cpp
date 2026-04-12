#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int hh[105],ll[105],h,l;
int main(){
	cin>>h>>l;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=l;++j){
			cin>>a[i][j];
			if(a[i][j]=='#') hh[i]=1;
		}
	for(int j=1;j<=l;++j)
		for(int i=1;i<=h;++i)
			if(a[i][j]=='#'){
				ll[j]=1;break;
			} 
	for(int i=1;i<=h;++i){
		if(!hh[i]) continue;
		for(int j=1;j<=l;++j){
			if(!ll[j]) continue;
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
