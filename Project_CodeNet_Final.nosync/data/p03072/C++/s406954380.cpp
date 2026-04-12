#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>

using namespace std;

int h[30];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k=0,n;
	cin>>n;
	for(i=1;i<=n;i++)cin>>h[i];
	for(i=1;i<=n;i++){
		int f = 1;
		for(j=1;j<=i;j++){
			if(h[j]>h[i])f = 0;
		}
		if(f == 1)++k;
	}
	cout<<k<<endl;
	return 0;
}
