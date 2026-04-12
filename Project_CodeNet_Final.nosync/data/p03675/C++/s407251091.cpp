#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) FOR((i),0,(n))

typedef long long ll;

const int INF=1e9+7;
const int MAX_N=2*1e5+5;
int a[MAX_N];
int main(){
	int n;
	cin>>n;
	rep(i,n)cin>>a[i+1];
	int now=n;
	while(now>1){
		cout<<a[now]<<" ";
		now-=2;
	}
	cout<<a[1];
	now=n%2==0?now=3:2;
	while(now<=n){
		cout<<" ";
		cout<<a[now];
		now+=2;
	}
	cout<<endl;
}
