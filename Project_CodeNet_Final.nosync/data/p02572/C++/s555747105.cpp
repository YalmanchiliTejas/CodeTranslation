#include<iostream>
using namespace std;
const long mod=1e9+7;
int main() {
    int N; cin>>N;
    long S=0,T=0;
	for (int i=0; i<N; i++) {
		long A; cin>>A;
		S = (S+A*T) % mod;
		T = (T+A) % mod;
	}
	cout<<S<<endl;
    return 0;
}