#include<iostream>
using namespace std;

int main(void){
	
	int N,sum=1,check;//sumは該当旅館の個数、	checkが0ならsum++、それ以外ではなにもしない
	
	cin>>N;
	
	int H[N];
	
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	
	for(int i=1;i<N;i++){
		check=0;//
		for(int j=0;j<i;j++){
			if(H[i]<H[j]){
				check=1;
				continue;
			}
		}
		if(check==0)
			sum++;
	}
	
	cout<<sum<<endl;
	
	return 0;
}