#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0) break;
		vvi d(n,vi(n,0));
		int x=n/2,y=n/2+1;
		rer(i,1,n*n){
			while(1){
				if(x<n && x>=0 && y<n && y>=0 && d[y][x]==0){
					d[y][x]=i; 
					break;
				}else if(x<n && x>=0 && y<n && y>=0 && d[y][x]){
					y++; x--;
				}
				if(x>=n) x-=n;
				if(x<0) x+=n;
				if(y>=n) y-=n;
			}
			x++; y++;
		}
		rep(i,0,n){
			rep(j,0,n){
				printf("%4d",d[i][j]);
			}
			printf("\n");
		}
	}
}