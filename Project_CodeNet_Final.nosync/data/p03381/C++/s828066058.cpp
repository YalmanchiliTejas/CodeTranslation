#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int a[maxn+5];
int b[maxn+5];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	
		for(int i=1;i<=n;i++){
			if(a[i]<=b[n/2]){
				cout<<b[n/2+1]<<endl;
			}else if(a[i]>b[n/2]){
				cout<<b[n/2]<<endl;
			}
		}
	
	return 0;
} 