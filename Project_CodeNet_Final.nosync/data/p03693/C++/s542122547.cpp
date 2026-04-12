#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cmath>
#include <limits>
#include<set>
#include <iomanip>
#include <queue>
#include <map>
#include <string>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const long long INF=(1LL<<62);
const double inf=pow(10,10);
double pi=3.141592653589793;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const ll MOD = 1000000007;
void init(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
ll N,A,B;
vector<ll>h(100005);
bool isOK(ll mid){
	ll ret=0;
	for(int i=0;i<N;i++){
		if(h[i]-mid*B>0){
			ret+=(h[i]-mid*B+(A-B)-1)/(A-B);
		}
	}
	return ret<=mid;
}


int main(){
	init();
	ll a,b,c;
	cin>>a>>b>>c;
	ll num=100*a+10*b+c;
	if(num%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
