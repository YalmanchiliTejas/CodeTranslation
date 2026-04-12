#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int n;
int a[200];

bool C(int t){
	int sum=0;
	rep(i,n){
		sum+=a[i];
		if(sum<t){
			return false;
		}
		sum-=t;
	}
	return true;
}
int main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	for(int i=10000;i>=1;i--){
		if(C(i)){
			cout<<i<<endl;
			return 0;
		}
	}
}
