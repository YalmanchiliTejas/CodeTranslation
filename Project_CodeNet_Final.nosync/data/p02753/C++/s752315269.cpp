#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define OUT(a) cout<<(a)<<endl
#define VECIN(type, c, n) vector<type> c(n);for(auto& i:c) cin>>i;


int main(){
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<=1;i++){
		if(s[i]!=s[i+1]) n=1;
		}
		if(n==0){
			OUT("No");
		}else{
			OUT("Yes");
		}
	return 0;
}