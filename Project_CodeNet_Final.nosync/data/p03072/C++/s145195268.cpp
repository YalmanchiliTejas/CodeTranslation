#include <bits/stdc++.h>
using namespace std;
int main(){
int n,maxv=-1,s=0;
cin>>n;
int a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]>=maxv){
		maxv=a[i];
		s++;
	}
} 
cout<<s;
}
