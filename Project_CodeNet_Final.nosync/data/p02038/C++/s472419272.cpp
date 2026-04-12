#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

int A[100001];
int main(){
	cin>>N;
	REP(i,N){
		string s;
		cin>>s;
		if(s[0]=='T'){
			A[i]=1;
		}else{
			A[i]=0;
		}
	}
	REP(i,N-1){
		if(A[i]==1&&A[i+1]==0){
			A[i+1]=0;
		}else{
			A[i+1]=1;
		}
	}
	if(A[N-1]==1){
		cout<<"T"<<endl;
	}else{
		cout<<"F"<<endl;
	}
}
