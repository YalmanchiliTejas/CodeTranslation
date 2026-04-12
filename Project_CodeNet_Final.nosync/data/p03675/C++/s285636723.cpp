#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,a[200010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	
	int cnt=n-1;
	if(cnt%2==(n%2))cnt--;
	for(int i=0;i<n;i++){
		cout<<a[cnt];
		if(i!=n-1)cout<<" ";
		
		if(cnt%2!=(n%2))cnt-=2;
		else cnt+=2;
		
		if(cnt<0)cnt=(n%2);
	}
	cout<<endl;
	return 0;
}
