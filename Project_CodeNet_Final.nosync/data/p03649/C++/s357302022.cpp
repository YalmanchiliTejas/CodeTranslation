#include <iostream>
using namespace std;

int n;
long long arr[55];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool found=true;
	long long sol=0;
	int cnt=0;
	while(found){
		cnt++;
		found=false;
		for(int i=0;i<n;i++){
			if(arr[i]>=n)found=true;
			else continue;
			long long times= arr[i]/n;
			
			arr[i] %= n;
			sol += times;
			
			for(int j=0;j<n;j++){
				if(j==i)continue;
				arr[j] += times;
			}
		}
	}
	//cout<<cnt<<endl;
	cout<<sol<<endl;
}