#include <iostream>
#include <algorithm>
using namespace std;

long long div(long long i){
	return (i+1)/2;
}
int main() {
	int n;
	long long x;
	cin >> n >> x;
	long long incP[n+1],incA[n+1];
	incP[0] = 1;
	incA[0] = 1;
	for(int i=1;i<n+1;i++){
		incP[i] = incP[i-1]*2+1;
		incA[i] = incA[i-1]*2+3;
	}
	long long ate = 0;
	for(int i=n;i>0;i--){
		if(div(incA[i])==x){
			ate+=1+incP[i-1];
			x=0;
		}
		else if(div(incA[i])<x){
			ate+=1+incP[i-1];
			x-= div(incA[i]);
		}
		else{
			if(x>0)
				x--;
		}
	}
		if(div(incA[0])==x){
			ate+=1;
			x=0;
		}
		else if(div(incA[0])<x){
			ate+=1;
			x-= div(incA[0]);
		}
		else{
			x--;
		}
	cout << ate << endl;
	return 0;
}