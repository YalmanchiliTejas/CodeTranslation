#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;

int main(){
	LL a,b,c,x;
	cin>>a>>b>>c;
	x = a*100+b*10+c;
	if(x%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}