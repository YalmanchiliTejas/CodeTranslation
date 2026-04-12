#include<iostream>
#include<algorithm>
using namespace std;
int a[12];
int main(){
	for(int i=0;i<12;i++)cin>>a[i];
	sort(a,a+12);
	bool ok=true;
	for(int i=0;i<12;i++){
		if(i%4!=3)if(a[i]!=a[i+1])ok=false;
	}
	if(ok)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}