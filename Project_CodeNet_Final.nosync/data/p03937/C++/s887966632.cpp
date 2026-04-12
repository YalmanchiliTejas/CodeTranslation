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
const long long INF=200000000000000;
double pi=3.141592653589793;

const int MOD = 1000000007;

long long gcd(long long a,long long b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	return gcd(a%b,b);
}

long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
long myPow(long long x, long long n, long long m=MOD){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

class Point{
public:
	long long x;
	long long y;
	long long dis;
	Point(long long _x,long long _y,long long _dis){
		x=_x;
		y=_y;
		dis=_dis;
	}
};

typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll H,W;
	ll num=0;
	cin>>H>>W;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			char a;
			cin>>a;
			if(a=='#')num++;
		}
	}
	if(num==H+W-1)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}
