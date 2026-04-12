#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cmath>
#include <limits>
#include<set>
#include <iomanip>
#include <queue>
#include <string>
#pragma GCC optimize("Ofast")
using namespace std;
const long long INF=20000000000;
//setprecision(2) <<

const int MOD = 1000000007;

long long max(long long a,long long b){
	if(a<b)return b;
	else return a;	
}
long long min(long long a,long long b){
	if(a>b)return b;
	else return a;	
}
long long gcd(long long a,long long b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	else return gcd(a%b,b);
}

long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}


long long getDigit(long long n){
	if(n==1)return 1;
	else return log10(n)+1;
}

class Point{
public:
	long long x;
	long long y;
};
long long N,M;
vector<long long>X(100006,0);
bool isOK(long long time){
	long right=0;
	for(int i=0;i<M;i++){
		if(right>=X[i]-1){
			//go right
			right=X[i]+time;
		}else{
			if(right < X[i]-time-2)return false;
			right=max(X[i],X[i]+(time-(2*(X[i]-right)-1)));
		}
		//cout<<right<<endl;
	}
	if(right<N-1)return false;
	return true;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long H,W;
	cin>>H>>W;
	char map[H][W];
	vector<bool>h(H,true);
	vector<bool>w(W,true);
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(map[i][j]=='#')h[i]=false;
		}
	}
	for(int j=0;j<W;j++){
		for(int i=0;i<H;i++){
			if(map[i][j]=='#')w[j]=false;
		}
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(h[i]==false && w[j]==false)cout<<map[i][j];
		}
		if(!h[i])cout<<endl;
	}
}
