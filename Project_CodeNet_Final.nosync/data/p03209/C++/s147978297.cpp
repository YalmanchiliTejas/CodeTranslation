#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;

vector<ll> num(55),p(55);

ll rec(int level, ll x){
	if(level == 0)return 1;//LEVEL0バーガー
	if(x == 1)return 0;//下のバン
	else if(x < (num[level]+1)/2)return rec(level-1,x-1);//下のL-1バーガー
	else if(x == (num[level]+1)/2)return p[level-1]+1;//真ん中のパティ
	else if(x < num[level])return rec(level-1,x-(num[level]+1)/2)+p[level-1]+1;//上のL-1バーガー
	else return p[level];//上のバン
}

int main(void){
	ll n,x;
	cin>>n>>x;

	num[0]=1;
	p[0]=1;
	rep(i,n){
		num[i+1]=2*num[i]+3;
		p[i+1]=2*p[i]+1;
	}

	cout<<rec(n,x)<<endl;
	return 0;
}
