#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	int count=0,ret=H[0];
	for(int i=0;i<N;i++){
		ret = max(ret,H[i]);
		if(H[i]==ret) count++;
	}
	cout<<count;
}