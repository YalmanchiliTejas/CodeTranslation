#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

long long max(long long a,long long b){
	return (a>=b)?a:b;
}

int main(){
	long long n,k;
	cin>>n>>k;
	long long sum=(k==0)?(n-1)*n/2:(n-k+1)*(n-k)/2;
	for(long long b=1;b<=n;b++){
		long long cnt=(n-b+1)/b,amari=(n-b+1)%b;
		if((amari-1)>=k)sum+=(amari-k);
		sum+=max(0,b-k)*cnt;
	}
	cout<<sum<<endl;
	return 0;
}