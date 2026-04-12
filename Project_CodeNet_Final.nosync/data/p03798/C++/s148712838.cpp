#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=1145141919810364364;

#define SHEEP 1
#define WOLF -1

int main(){
	int n; cin>>n;
	string s; cin>>s;
	int a[n]={};
	for(int i=0;i<(1<<2);i++){
		rep(j,2){
			if(i>>j&1) a[j]=SHEEP;
			else a[j]=WOLF;
		}
		for(int j=1;j<=n-2;j++){
			if(s[j]=='o'){
				if(a[j]==SHEEP) a[j+1]=a[j-1];
				else a[j+1]=-a[j-1];
			}else{
				if(a[j]==SHEEP) a[j+1]=-a[j-1];
				else a[j+1]=a[j-1];
			}
		}
		bool flg1=0;
		if((s[n-1]=='o'&&a[n-1]==SHEEP)||(s[n-1]=='x'&&a[n-1]==WOLF)){
			if(a[0]*a[n-2]==1) flg1=1;
		}else{
			if(a[0]*a[n-2]==-1) flg1=1;
		}
		bool flg2=0;
		if(flg1){
			if((s[0]=='o'&&a[0]==SHEEP)||(s[0]=='x'&&a[0]==WOLF)){
				if(a[1]*a[n-1]==1) flg2=1;
			}else{
				if(a[1]*a[n-1]==-1) flg2=1;
			}
		}
		if(flg2){
			for(auto i:a){
				if(i==SHEEP) cout<<'S';
				else cout<<'W';
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
