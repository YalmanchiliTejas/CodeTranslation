#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define LONG LLONG_MAX/3;
#define INT INT_MAX/3;
#define mod 1000000007
#define S second
#define F first
typedef long long ll;
using namespace std;
char c[100][100];
bool b[100][100];
int main(){
	int n,m;
	cin>>n>>m;
	f(i,n){
		bool a=false;
		f(j,m){
			cin>>c[i][j];
			if(c[i][j]=='#'){
				a=true;
			}
		}
		if(!a){
			f(j,m) b[i][j]=true;
		}
	}
	f(j,m){
		bool a=false;
		f(i,n){
			if(c[i][j]=='#') a=true;
		}
		if(!a){
			f(i,n) b[i][j]=true;
		}
	}
	
	f(i,n){
		bool a=false;
		f(j,m){
			if(!b[i][j]){
				cout<<c[i][j];
				a=true;
			}
		}
		if(a) puts("");
	}
	return 0;
}
