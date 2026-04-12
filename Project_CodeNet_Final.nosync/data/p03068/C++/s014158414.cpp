#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int len,k;
int main()
{
	cin>>len>>a>>k;
	for(int i=0;i<len;i++){
		if(a[i]!=a[k-1])
			a[i]='*';
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}