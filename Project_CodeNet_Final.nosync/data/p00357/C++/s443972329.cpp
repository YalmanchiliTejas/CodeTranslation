#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
using namespace std;
//
const int inf=1e9+7;
const int mod=1e9+7;
//
struct poi{
	int X;int Y;int Z;
	bool operator<(const poi&R)const{
		return X==R.X ? Y==R.Y ? Z<R.Z : Y<R.Y : X<R.X;
	}
};
//
ll GCD(ll a,ll b){
	return (b==0)?(a):(GCD(b,a%b));
}
ll LCM(ll a,ll b){
	return a/GCD(a,b)*b;
}
//
int main(){
	int N;
	cin>>N;
	vector<int> D(N);
	FOR(i,0,N){
		cin>>D[i];
	}
	int now=0,ok=0;
	while(now<N){
		ok=max(ok,now+D[now]/10);
		now++;
		if(ok<now){
			cout<<"no"<<endl;
			return 0;
		}
	}
	now=N-1;ok=N-1;
	while(now>=0){
		ok=min(ok,now-D[now]/10);
		now--;
		if(ok>now){
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"yes"<<endl;
	return 0;
}
