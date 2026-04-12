#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
#include<string>
using namespace std;
typedef long long LL;
LL a[51],b[51];
int main(){
	string s;
	LL n,m;
	cin>>n>>m;
	a[0] = 1;
	b[0] = 1;
	for(int i=1;i<=n;i++){
		a[i] = a[i-1]*2+1+2;
		b[i] = b[i-1]*2+1;
	}
	int zd;
	int i = n;
	LL sum = 0;
	int f = 0;
	while(m>0){
		if(m>=a[i]){
			m-=a[i];
			sum+=b[i];
			if(m>=1){
				sum++;
				m--;
			}
		}
		else{
			i--;
			m--;
		}
	}
	cout<<sum<<endl;
	return 0;
} 