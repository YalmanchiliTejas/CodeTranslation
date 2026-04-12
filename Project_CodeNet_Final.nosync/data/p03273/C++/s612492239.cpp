#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdio.h>
#include<vector>
#define int long long
using namespace std;
#define rep(s,i,n) for(int i=s;i<n;i++)
#define c(n) cout<<n<<endl;
#define ic(n) int n;cin>>n;
#define sc(s) string s;cin>>s;
char a[114][114];
int b[114],c[114];
signed main(){
	ic(h) ic(w)
	rep(0,i,h)rep(0,j,w)cin>>a[i][j];
	int sum=0;
	rep(0,i,h){
		sum=0;
		rep(0,j,w){
			if(a[i][j]=='#'){	
				sum++;
			}
		}
		if(sum==0){
			b[i]=1;
		}
	}
	rep(0,i,w){
		sum=0;
		rep(0,j,h){
			if(a[j][i]=='#'){	
				sum++;
			}
		}
		if(sum==0){
			c[i]=1;
		}
	}
	rep(0,i,h){
		sum=0;
		rep(0,j,w){
			if(b[i]==0&&c[j]==0){
				cout<<a[i][j];
				sum++;
			}	
		}
		if(sum>0)cout<<endl;	
	}
}				
