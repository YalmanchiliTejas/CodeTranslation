#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int a[100]={0};
	for(int i=0;i<12;i++) cin>>a[i];
	sort(a,a+12);
	for(int i=0;i+3<12;i+=4){
		if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i+2]==a[i+3]) continue;
		else{
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"yes"<<endl;
	return 0;
}