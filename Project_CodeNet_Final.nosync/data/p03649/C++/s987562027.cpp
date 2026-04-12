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
		if(cnt>k)return false;
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
		bool ok=false;
		for(int i=0;i<51;i++){
			if(F(i+mid)){
				ok=true;
				if(ret>i+mid)ret=i+mid;
			}
		}
		if(ok){
			right=mid;
		}
		else left=mid+1;
	}
	bool ok=true;
	for(int i=0;i<n;i++)if(a[i]>=n)ok=false;
	if(ok)ret=0;
	cout<<ret<<endl;
	return 0;
}
