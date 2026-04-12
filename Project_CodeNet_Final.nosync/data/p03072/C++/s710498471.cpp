#include<bits/stdc++.h>
#define REP(i,n)for(int i=0;i<n;i++)
#define REPR(i,n)for(int i=n;i>=0;i--)
#define FOR(i,m,n)for(int i=m;i<n;i++)
#define INF 999999999
#define llong long long

using namespace std;

int main(){
	int N;
	cin>>N;
	int H[N];
	REP(i,N){cin>>H[i];}

	int num=1;
	int flag;
	for(int i=N-1;0<i;i--){
		flag=0;
		for(int j=i-1;0<=j;j--){
			if(H[i]<H[j]){
				flag=-1;
				break;
			}
		}
		if(flag==0){num++;}

	}
	cout<<num<<endl;
	
	
	return 0;

}
