#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define INF 10e20
static const int MAX_N=10e5,MAX_M=10e5;
long long N,M,K,X,Y,Z;
int maxs=-1,mini=INF,ans,res;
long long A[MAX_N],B[MAX_N],C[MAX_N];
int a,b,c,d,e,f,g;
int x,y,z;
int i,j,k,l,m,n;
#define rep(i,ra,re) for((i)=ra;(i)<(re);(i)++)
#define rep_(i,ra,re) for((i)=ra;(i)<=(re);(i)++)
#define put(n) cout << n << " "; 

long long pan(int i,long long val){
	if(i<=0)
		return val;
	else if(val<=1)
		return 0;
	
	if(val<A[i-1]+2)
		return pan(i-1,val-1);
	else if(val==A[i-1]+2)
		return B[i-1]+1;
	else if(val<=A[i]-1)
		return (long long)B[i-1]+1+pan(i-1,val-2-A[i-1]);
	else
		return B[i];
}


int main(void){
	cin >> N >> M;
	A[0]=1;
	B[0]=1;
	rep(i,0,N){
		A[i+1]=A[i]*2+3;
		B[i+1]=B[i]*2+1;
	}
	cout << pan(N,M) << endl;
	return 0;
}