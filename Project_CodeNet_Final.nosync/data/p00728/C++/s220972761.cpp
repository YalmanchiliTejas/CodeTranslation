#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int main(){
	int i,j,k,l,m,n;
	while(cin>>n){
		if(n==0) break;
		int mx=0, mn=2000;
		k=0;
		rep(i,n){
			cin >> m;
			mx = max(mx,m);
			mn = min(mn,m);
			k+=m;
		}
		cout << (k-mx-mn)/(n-2) << endl;
	}
}