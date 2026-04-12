#include <iostream>
//#include <cmath>
using namespace std;
using ll=long long;
using ld=long double;

void solve(long long N, long long K){
  N++;

  ll cnt = 0;
  for(ll b=K; b<N; b++){
    if(b>0){
      //cout << b << ","<< (N/b) * (b-K) << endl;;
      cnt += (N/b) * (b-K);
      if(N%b-K > 0) cnt += N%b-K;
    }
  }
  //cout<< "######" << endl;
  //
  // K = 0 のとき、a=0 がカウントされてしまうので、除く。
  if(K==0) cnt -= N-1;
  
  cout << cnt << endl;
}

int main(){	
	long long K;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&K);
	solve(N, K);
	return 0;
}

