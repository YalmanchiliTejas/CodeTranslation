#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
int a,b=0,c=0,aa[100];
signed main()
{
	cin>>a;
	rep(i,a){
		cin>>aa[i];
		if(c<=aa[i]){
			b++;
			c=aa[i];
		}
	}
	cout<<b;
}