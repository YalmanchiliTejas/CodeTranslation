#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> b;
	int i;
	for(i=n-1;i>=0;i-=2){
		cout<<a[i]<<' ';
	}
	for(i=-1-i;i<n;i+=2){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
