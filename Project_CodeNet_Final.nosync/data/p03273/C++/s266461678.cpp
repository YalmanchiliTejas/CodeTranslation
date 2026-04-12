#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define DEKAI 1000000007
/* ┗(^o^)┛ｗｗｗｗｗ┏(^o^)┓ﾄﾞｺﾄﾞｺﾄﾞｺﾄﾞｺｗｗｗｗｗ */

int main(){
	int h,w;
	cin>>h>>w;
	char a[100][100];
	lp(i,h){
		lp(j,w){
			cin>>a[i][j];
		}
	}
	int x[100],y[100];
	lp(i,100){
		x[i]=0;
		y[i]=0;
	}
	lp(i,h){
		int stat=0;
		lp(j,w){
			if(a[i][j]=='#'){
				stat=1;
				break;
			}
		}
		if(stat==0){
			y[i]=1;
		}
	}
	lp(i,w){
		int stat=0;
		lp(j,h){
			if(a[j][i]=='#'){
				stat=1;
				break;
			}
		}
		if(stat==0){
			x[i]=1;
		}
	}
	lp(i,h){
		if(y[i]==1) continue;
		lp(j,w){
			if(x[j]==1) continue;
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}