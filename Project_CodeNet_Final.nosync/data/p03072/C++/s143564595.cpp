#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define INF 1e9
typedef long long llong;
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int top=0;
	int ans=0;
	REP(i,n){
		int tmp;
		cin>>tmp;
		if(tmp>=top) ans++;
		top=max(top,tmp);
	}
	
	cout<<ans<<endl;
}