#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
typedef LL T;

// powmod p^n%mod
T powmod(T p,T n,T mod){
	T q=p%mod;
	T pow=1;
	while(n){
		if(n&1){
			pow*=q;
			pow%=mod;
		}
		q=q*q;
		q%=mod;
		n/=2;
	}
	return pow;
}

LL C[3001][3001];
LL N,M;
LL S[3001][3002];

LL f(LL k){
	LL s=0;
	// (b+1)*S[k][b+1]+S[k][b] は k 元集合の部分集合を b 個の集合に分ける方法の数
	for(int b=0;b<=k;b++){
		s+=((b+1)*S[k][b+1]%M+S[k][b])%M*powmod(2,(N-k)*b,M)%M;
		s%=M;
	}
	return s;
}
int main() {
	cin >> N >> M;
	for(int i=0;i<=3000;i++){
		C[i][0]=1;
		if(i==0){
			S[i][0]=1;
		}
		else{
			S[i][0]=0;
		}
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=M;
			S[i][j]=S[i-1][j-1]+j*S[i-1][j]%M;
			S[i][j]%=M;
		}
	}
	LL r=0;
	for(LL i=0;i<=N;i++){
		LL a=f(i);
		LL e=powmod(2,N-i,M-1);
		LL d=powmod(2,e,M);
		LL s=a*d%M;
		s*=C[N][i];
		s%=M;
		if(i%2==0){
			r+=s;
			r%=M;
		}
		else{
			r+=M-s;
			r%=M;
		}
	}
	cout << r << endl;

	return 0;
}

