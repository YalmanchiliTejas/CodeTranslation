#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int MAX_N=1e5+5;
int n,m;
int a[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==3||n==5||n==7)	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	
	
	return 0;
}