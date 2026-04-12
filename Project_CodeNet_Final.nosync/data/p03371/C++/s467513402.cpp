#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
typedef long long ll;
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
int INF=2e+9+1;
int main(){
	int A,B,C,X,Y;
	scan(A);scan(B);scan(C);scan(X);scan(Y);
	if(A+B<2*C){
		prin(A*X+B*Y);
	}
	else{
		int AB2num=min(X,Y);
		int kane=2*C*AB2num;
		X-=AB2num;
		Y-=AB2num;
		kane+=min(A*X+B*Y,2*C*max(X,Y));
		prin(kane);
	}
	return 0;
}
