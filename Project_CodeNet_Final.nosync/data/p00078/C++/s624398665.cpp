#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<complex>
#include<stack>
#include<cmath>
 
using namespace std;
 
#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

#define X real()
#define Y imag()
typedef complex<double> P;

int main(){
	
	int n;
	while(cin>>n,n){
		
		int masu[33][33]={0};
		int stx = n/2;
		int sty = n/2+1;
		
		int cnt = 1;
		
		while(cnt<=n*n){
			if(masu[sty%n][stx%n]==0){
				masu[sty%n][stx%n]=cnt;
				sty++;
				stx++;
				cnt++;
			}
			if(masu[sty%n][stx%n]!=0){
				sty++;
				stx--;
			}
		}
		
		rep(i,n){
			rep(j,n){
				printf("%4d",masu[i][j]);
			}puts("");
		}
	}
	
}