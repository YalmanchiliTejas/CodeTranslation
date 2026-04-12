#include<iostream>

using namespace std;

int main(){

	int n;
	int inp;
	int sum,max,min;

	while(1){

		cin>>n;
		if(n==0) break;

		cin>>inp;
		min=inp,max=inp,sum=inp;
		for(int i=1;i<n;i++){
			cin>>inp;
			sum+=inp;
			if(min>inp) min=inp;
			if(max<inp) max=inp;
		}
		cout<<(sum-min-max)/(n-2)<<endl;
	}

	return 0;
}