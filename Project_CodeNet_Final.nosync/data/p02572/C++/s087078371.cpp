#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int N;
	long ans=0;
	long total=0;
	long mod=1000000007;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin >> A.at(i);
		total+=A.at(i);
        total%=mod;
	}
	for(int i=0;i<N;i++){
		if(total<A.at(i))
          total+=mod;
      	total-=A.at(i);
		ans+=(total*A.at(i))%mod;
	}
	cout << ans%mod <<endl;
}
