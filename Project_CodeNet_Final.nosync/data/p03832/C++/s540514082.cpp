#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 100000000

//aのb乗
int beki(int a,int b,int M = modulo){
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
	
	int catalan(int n){
		return mod(combination(2*n,n)*gyakugen(n+1));
	}
	
};

int main() {
	
	int N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	combi c(10000);
	
	vector<vector<int>> dp(N+2,vector<int>(N+1,0));
	dp[0][0] = 1;
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dp[i+1][j] = mod(dp[i][j]+dp[i+1][j]);
			if(i>=A&&i<=B){
				int temp = N-j;
				int t = 1;
				for(int k=1;k<=D;k++){
					if(temp<i)break;
					t = mod(t * c.combination(temp,i));
					int x = mod(t * c.kaijou_[k]);
					if(k>=C)dp[i+1][j+k*i] = mod(dp[i+1][j+k*i] + mod(x*dp[i][j]));
					temp-=i;
				}
			}
		}
	}
	
	cout<<dp.back().back()<<endl;
	
    return 0;
}
