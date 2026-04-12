#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int f=0;
		cin>>a[i];
		if(i==1){
			++s;
			continue;
		}
		for(int j=1;j<i;j++){
			if(a[j]>a[i]){
				f=1;
				break;
			}
		}
		if(f==0)++s;
	}
	cout<<s<<endl;
	return 0;
}