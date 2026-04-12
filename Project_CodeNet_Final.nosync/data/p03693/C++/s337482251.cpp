#include<bits/stdc++.h>
#define rep(i,a,b)  for (__typeof(b) i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=1-2*((a)>(b)))
using namespace std;
typedef long long ll;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	a*=100;
	b*=10;
	a = a+b+c;
	if(a%4 == 0) cout <<"YES";
	else cout <<"NO";
	return 0;
}