#include<iostream>
using namespace std;

int main(){
	int n;
	
	cin>>n;
	
	for(int i = 0; i < (1<<n); i++){
		cout<<i<<":";
		for(int j = 0, k = i; k; j++){
			if(k&(1<<j)){
				cout<<" "<<j;
				k &= ~(1<<j);
			}
		}
		cout<<endl;
	}
	
	return 0;
}
