#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int N;
long long S,T;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		long long A;
    	cin>>A;
		S=(S+A*T)%mod;
		T=(T+A)%mod;
	}
	cout<<S<<endl;
  return 0;
}