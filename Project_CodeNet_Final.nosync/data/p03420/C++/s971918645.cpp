#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int main(){
//	long long n,m;
//	while(scanf("%d%d",&n,&m)==2){
//		long long sum;
//		sum = (n-2)*(m-2);
//		if(sum< 0) cout<<-sum<<endl;
//		else cout<<sum<<endl; 
//	}
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		long long sum;
		sum = 0;
			for(int b = k+1; b<=n;b++){
				sum += (n/b)*(b-k); 
				int i=n%b-k+1;
				if(i>=0) sum += i;
			}
		if(k==0) sum -= n;
		cout<<sum<<endl;
	}
}  