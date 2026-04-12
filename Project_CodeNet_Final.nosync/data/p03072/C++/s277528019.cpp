#include<iostream>
using namespace std;

int main(void){
	
	int N,sum=1,check;
	
	cin>>N;
	
	int H[N];
	
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	
	for(int i=1;i<N;i++){
		check=0;
		for(int j=0;j<i;j++){
			if(H[i]<H[j])
				check=1;
		}
		if(check==0)
			sum++;
	}
	
	cout<<sum<<endl;
	return 0;
}