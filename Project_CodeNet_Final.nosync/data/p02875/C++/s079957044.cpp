#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
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
	
	void kaijou_set(int n){
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
	
	combi C;
	C.kaijou_set(10000001);
	
	int N;
	cin>>N;
	
	int k = N/2 + 1;
	
	int bb = beki(2,N-k);
	int sum = 0;
	int gya = gyakugen(2);
	for(int i=k;i<=N;i++){
		int a = C.combination(N,i);
		int b = mod(a * bb);
		
		sum = mod(sum + b);
		
		bb = mod(bb * gya);
	}
	
	sum = mod(sum * 2);
	
	int ans = beki(3,N);
	ans = mod(ans - sum);
	cout<<ans<<endl;
	
    return 0;
}

