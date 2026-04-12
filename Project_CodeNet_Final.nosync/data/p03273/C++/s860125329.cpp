#include <iostream>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
//const int MAX=;

int main(){
	int H,W;
	cin>>H>>W;
	char b[100][100];
	rep(i,H)rep(j,W)cin>>b[i][j];
	
	int r[100]={};
	int c[100]={};
	rep(i,H){
		int flag=0;
		rep(j,W){
			if(b[i][j]!='.')flag=1;
		}
		r[i]=flag;
	}
	rep(j,W){
		int flag=0;
		rep(i,H){
			if(b[i][j]!='.')flag=1;
		}
		c[j]=flag;
	}
	rep(i,H){
      	if(r[i]==0) continue;
		rep(j,W){
			if(c[j])cout<<b[i][j];
		}
		cout<<endl;
	}
}
