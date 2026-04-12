#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[20000],b[20000];
int main(){
	int n,m,z;
	while(true){
	cin>>n>>m;
	if(n==0&&m==0)
		break;
	for(int i=0;i<n;i++){
		cin>>z;
		a[i]=z;
	}
	for(int i=0;i<m;i++){
		cin>>z;
		a[i+n]=z;
	}
	sort(a,a+n+m);
	b[n+m-1]=a[0];
	for(int i=0;i<n+m-1;i++){
		b[i]=a[i+1]-a[i];
	}
	sort(b,b+n+m);
	cout<<b[n+m-1]<<endl;
	}
	return 0;
}