#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<long long> V(N);
  int mod=1000000007;
  long long sum=0;
  long long s=0;
  for(int i=0;i<N;i++)
  {
	  cin>>V[i];
	  sum+=V[i];
	  sum%=mod;
  }
  for(int i=0;i<N;i++)
  {
	  sum-=V[i];
	  if(sum<0) sum+=mod;
	  s+=sum*V[i];
	  s%=mod;
  }
  cout<<s%mod<<endl;
}