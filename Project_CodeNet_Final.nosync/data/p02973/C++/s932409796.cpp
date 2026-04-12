#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	int B[N+1]; int x;
	rep(i,0,N+1) B[i] = -1;
	rep(i,0,N){
		cin>>x;
		int a = -1,b = N-1;
		while(b - a > 1){
			int m = (a + b) / 2;
			if(B[m] >= x) a = m;
			else b = m;
		}B[b] = x;
	}
	rep(i,0,N+1){
		if(B[i] == -1){ cout<<i<<endl; break; }
	}
}