#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define double long double

int n,a[110];

bool check(int s){
	int now=0;
	for(int i=0;i<n;i++){
		now+=a[i];
		if(now-s<0)return false;
		now-=s;
	}
	return true;
}

void input(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	return;
}

void solve(){
	for(int j=100;j>=1;j--){
		if(check(j)){
			cout<<j<<endl;
			return;
		}
	}
	return;
}

int main(){
	input();
	solve();
	return 0;
}
