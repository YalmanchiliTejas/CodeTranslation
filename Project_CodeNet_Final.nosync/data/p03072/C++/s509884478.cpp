#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int H[N];
	for(int i=0;i<N;i++){
		int h;
		cin>>h;
		H[i]=h;
	}
	int number =1;
	for(int i=1;i<N;i++){
		int kaisu=0;
		for(int j=0;j<i;j++){
			if(H[i]>=H[j]){
				kaisu += 1;	
			}
		}
		if(kaisu == i){
			number += 1;
		}
	}
	cout<<number;
	return 0;
}	
