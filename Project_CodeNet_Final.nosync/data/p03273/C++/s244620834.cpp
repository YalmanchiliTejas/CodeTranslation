#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int inf=100000000;
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
	char a[110][110];
int s[110][110];
int main(){
	int h,w;
	cin>>h>>w;
	
	rep(i,0,h){
		rep(j,0,w){
			cin>>a[i][j];
			s[i][j]=1;
		}
	}
	rep(i,0,h){
		int x=0;
		rep(j,0,w){
			if(a[i][j]=='.')x++;
		}
		if(x==w){
			rep(k,0,w)s[i][k]=0;
		}
	}
	rep(i,0,w){
		int x=0;
		rep(j,0,h){
			if(a[j][i]=='.')x++;
		}
		if(x==h){
			rep(k,0,h)s[k][i]=0;
		}
	}
	rep(i,0,h){
		int x=0;
		rep(j,0,w){
			if(s[i][j]==1){
				cout<<a[i][j];
				x++;
			}
		}
		if(x!=0)cout<<endl;
	}
}