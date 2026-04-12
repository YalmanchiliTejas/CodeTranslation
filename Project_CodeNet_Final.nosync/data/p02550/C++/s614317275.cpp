#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,x,m,sum=0;
	cin >> n >> x >> m;
	long long a=x,b=0,totyu;
	for(long long i=0;i<n;i++){
		sum+=a;
		a=(a*a)%m;
		if(a==0){
			break;
		}else if(a==1){
			sum+=n-i-1;
			break;
		}else if(a==b){
			sum=totyu+(sum-totyu)*((n-101)/(i-100));
			i=100+(i-100)*((n-101)/(i-100));
		}
		if(i==100){
			b=a;
			totyu=sum;
		}
	}
	cout << sum << endl;
}