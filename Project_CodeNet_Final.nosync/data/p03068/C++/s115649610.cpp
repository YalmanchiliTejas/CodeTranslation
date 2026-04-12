#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for(int i = n; i >= 0; ++i)
#define FDS(i, n) for(ll i = 0; i < n; ++i)
#define FDSR(i, n) for(int i = n; i >= 0; ++i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m;i >= n;--i)
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define itn int
#define ednl endl
using namespace std;
typedef long long ll;
int main(){
	int N,K;
	string S;
	cin>>N;
	cin>>S;
	cin>>K;
	FDS(i,N){
		if(S.at(K-1)!=S.at(i)){
			cout<<'*';
		}
		else{
			cout<<S.at(i);
		}
	}
	cout<<endl;
}