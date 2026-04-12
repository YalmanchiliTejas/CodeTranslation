#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int beki(long long a,long long b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


int gyakugen(int a){
	return beki(a,modulo-2);
}


int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	int ans = 0;
	for(int i=0;i<N;i++){
		cin>>A[i];
		ans = mod(ans + A[i]);
	}

	ans = mod(ans * ans);
	
	for(int i=0;i<N;i++){
		ans = mod(ans - mod(A[i]*A[i]));
	}
	
	cout<<mod(ans * gyakugen(2))<<endl;
	
	return 0;
}
