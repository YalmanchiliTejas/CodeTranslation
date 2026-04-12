#include <iostream>
using namespace std;

int main() {
int n;
while(cin>>n){
	if(n==0){
		break;
	}
	int sum=0,max=0,min=1000,score;
	for(int k=0;k<n;k++){
		cin>>score;
		sum=sum+score;
		if(score>max){
			max=score;
		}
		if(score<min){
			min=score;
		}
	}
	cout<<(sum-max-min)/(n-2)<<endl;
}
	return 0;
}