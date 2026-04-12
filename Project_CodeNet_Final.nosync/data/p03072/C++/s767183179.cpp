#include <iostream>
#include <string>
#include <vector> 
using namespace std;
int main(void){
	int n;
	cin>>n;
	int max=0;
	int count =0;
	for(int i=0;i<n;i++){
		int a;
		cin >>a;
		if(a>=max){
			max=a;
			count++;
		}
	}
	cout<<count;
	return 0;
}