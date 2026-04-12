#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

int main(){
  long long N;
  cin>>N;
  vector<long long> A(N);
  vector<long long> r(N+1);
  r[0] = 0;
  long long sum=0;
  long long mod = 1000000000+7;
  long long ans=0;
  long long m=0;

  for(long long i=0;i<N;i++){
    cin>>A[i];
    r[i+1] = r[i] + A[i];
    
  }

  for(long long i=0;i<N-1;i++){
    sum += A[i] * ((r[N] - r[i+1])%mod);
    sum %= mod;

    

  }


	ans = sum;
	cout << ans << endl;

}
