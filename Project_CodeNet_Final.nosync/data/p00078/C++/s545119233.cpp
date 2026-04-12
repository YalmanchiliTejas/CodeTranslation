#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef pair<double,double> P;
typedef complex<double> CP;
typedef long long ll;

int m[16][16];
int n;
int cou=0;

void magic(int a,int b){
	if(a==n&&b==n) magic(0,0);
	else{
		if(a>=n) magic(0,b);
		else if(b>=n) magic(a,0);
		else if(a<0) magic(n-1,b);
		else if(m[a][b]>0) magic(a-1,b+1);
		else{
			m[a][b]=cou;
			cou++;
			if(cou==n*n+1) return;
			magic(a+1,b+1);
		}
	}
}

int main(){
	while(cin>>n,n!=0){
		rep(i,n)rep(j,n) m[i][j]=0;
		
		cou=1;
		int x=(n+1)/2-1;
		int y=x+1;
		magic(x,y);
		rep(i,n){
			rep(j,n){
				printf("%4d",m[j][i]);
			}
			cout<<endl;
		}
	}
	return 0;
}