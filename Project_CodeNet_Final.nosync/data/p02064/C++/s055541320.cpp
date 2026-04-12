#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;
//long long int N,M,K,L,R,H,W;

//const long long int MOD=1000000007;
const int MOD=1000000007;
//const long long int MOD=998244353;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>L>>R;
	vector<int>Ldis(N+2);
	vector<int>Rdis(N+2);
	cout<<"? "<<L<<" "<<R<<endl;
	cin>>K;
	vector<pair<int,int>>v;
	for(int i=1;i<=N;i++){
		cout<<"? "<<L<<" "<<i<<endl;
		cin>>H;
		cout<<"? "<<i<<" "<<R<<endl;
		cin>>W;
		if(H+W==K){
			v.push_back({H,i});
		}
	}
	sort(v.begin(),v.end());
	cout<<"!";
	for(auto i:v)cout<<" "<<i.second;
	cout<<endl;
	return 0;
}
