#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
typedef pair<int,P>P2;
#define F first
#define S second

string s;

signed main(){
	int n;
	cin>>n;
	int a[n];
	r(i,n)cin>>a[i];
	int s=0,x=0;
	r(i,n){
		if(a[i]>=x)s++;
		x=max(a[i],x);
	}
	cout<<s<<endl;
}