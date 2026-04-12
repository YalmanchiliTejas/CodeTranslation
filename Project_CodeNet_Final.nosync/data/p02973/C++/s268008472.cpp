#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){

	int N;
	cin>>N;
	
	vector<int> A(N);
	
	for(int i=0;i<N;i++)cin>>A[i];
	
	multiset<int> S;
	
	for(int i=0;i<N;i++){
		auto it = S.lower_bound(A[i]);
		if(it==S.begin())S.insert(A[i]);
		else{
			it--;
			S.erase(it);
			S.insert(A[i]);
		}
	}
	
	cout<<S.size()<<endl;
	
	
	return 0;
}