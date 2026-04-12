#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n;
long long a[60];
 
bool F(long long k){
	long long cnt=0;
	for(int i=0;i<n;i++){
		long long b=a[i]-n+1+k;
		cnt+=b/(n+1);
		if(b%(n+1)>0)cnt++;
	}
	if(cnt<=k)return true;
	return false;
}
 
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	long long left=0,right=600000000000000000,mid;
	long long ret=914514114514114514;
	while(left<right){
		mid=(left+right)/2;
		if(F(mid)==true){
			right=mid;
			if(ret>mid)ret=mid;
		}
		else left=mid+1;
	}
	long long w=ret;
	for(int i=0;i<999;i++){
		if(w-i<0)break;
		if(F(w-i)==true){
			ret=w-i;
		}
	}
	cout<<ret<<endl;
	return 0;
}