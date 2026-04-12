#include<iostream>
using namespace std;

int main(){
	int n,sum,max,min;
	while(cin>>n&&n>0){
		int S;
		min=1000000000;
		max=0;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>S;
			sum+=S;
			if(min>S){
				min=S;
			}
			if(max<S){
				max=S;
			}
		}
		sum-=(min+max);
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}