#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
char a[8][8];
signed main(){
	int h,w,cnt=0;
	cin>>h>>w;
		rep(i,h){
			rep(j,w){
				cin>>a[i][j];
			}
		}
		rep(i,h){
			rep(j,w){
				if(a[i][j]=='#')cnt++;
			}
		}
		if(cnt==h+w-1)puts("Possible");
		else puts("Impossible");
}
		
		
