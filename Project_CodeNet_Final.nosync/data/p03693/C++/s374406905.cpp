#include<bits/stdc++.h>

using namespace std;

int main()
{ 
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	int sum=a[0]*100+a[1]*10+a[2];
	if(sum%4==0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}