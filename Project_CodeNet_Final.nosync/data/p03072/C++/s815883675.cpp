#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N,max=0,count=0;
	cin>>N;
	vector<int>H(N);
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	for(int i=0;i<N;i++){
		if(H[i]>=max){
			count++;
			max=H[i];
		}
	}
	cout<<count<<endl;
	return 0;
}
