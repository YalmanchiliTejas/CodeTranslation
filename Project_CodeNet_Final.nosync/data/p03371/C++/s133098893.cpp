#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=300005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli arr[MaxN];
	void solve(){
		lli N,i,j,res=0,p;
		lli A,B,C,X,Y;
		cin>>A>>B>>C>>X>>Y;
		p=min(X,Y);
		if(C*2<A+B){
			res+=C*p*2;
			X-=p;
			Y-=p;
		}
		if(C*2<A){
			res+=X*C*2;
			X=0;
		}
		if(C*2<B){
			res+=Y*C*2;
			Y=0;
		}
		res+=X*A;
		res+=Y*B;
		cout<<res;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
