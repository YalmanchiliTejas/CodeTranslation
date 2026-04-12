#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max_value=0;
	int count=0;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(temp>=max_value){
			count++;
			max_value=temp;
		}
	}
	cout<<count;
	return 0;
}