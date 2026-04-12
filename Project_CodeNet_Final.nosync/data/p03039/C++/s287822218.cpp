#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

//aのb乗
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

//aの逆元
int gyakugen(int a){
	return beki(a,modulo-2);
}

struct combi{
	deque<int> kaijou;
	deque<int> kaijou_;
	
	combi(int n){
		kaijou.push_back(1);
		for(int i=1;i<=n;i++){
			kaijou.push_back(mod(kaijou[i-1]*i));
		}
		
		int b=gyakugen(kaijou[n]);
		
		kaijou_.push_front(b);
		for(int i=1;i<=n;i++){
			int k=n+1-i;
			kaijou_.push_front(mod(kaijou_[0]*k));
		}
	}
	
	int combination(int n,int r){
		if(r>n)return 0;
		int a = mod(kaijou[n]*kaijou_[r]);
		a=mod(a*kaijou_[n-r]);
		return a;
	}
	
	int junretsu(int a,int b){
		int x = mod(kaijou_[a]*kaijou_[b]);
		x=mod(x*kaijou[a+b]);
		return x;
	}
	
};

int main(){
	
	int N,M,K;
	cin>>N>>M>>K;
	
	combi C(N*M);
	
	int x = 0;
	
	for(int i=1;i<=N-1;i++){
		int a = mod((N-i)*M);
		a = mod(a*M);
		a = mod(a*i);
		x = mod(x+a);
	}
	//cout<<x<<endl;
	
	x = mod(x * C.combination(N*M-2,K-2));

	
	int y = 0;
	for(int i=1;i<=M-1;i++){
		int a = mod((M-i)*N);
		a = mod(a*N);
		a = mod(a*i);
		y = mod(y+a);
	}
	
	y = mod(y*C.combination(N*M-2,K-2));
	

	
	cout<<mod(x+y)<<endl;
		
	
	return 0;
	
}
