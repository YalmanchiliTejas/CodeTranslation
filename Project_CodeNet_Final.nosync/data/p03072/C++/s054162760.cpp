#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int h[30];
int main(){
	int n;cin>>n;
	rep(i,n)cin>>h[i];
	int cnt=0;
	rep(i,n){
		bool ok=true;
		for(int j=0;j<i;j++){
			if(h[j]>h[i])ok=false;
		}
		if(ok)cnt++;
	}
	cout<<cnt<<endl;
}