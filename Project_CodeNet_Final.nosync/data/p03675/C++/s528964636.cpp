#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	int n;
	cin>>n;
	vector<LL> a(n);
	int i;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	if (n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	for (i=n-1;i>=0;i-=2){
		cout<<a[i]<<" ";
	}
	if (n%2==0){
		i=0;
	}else{
		i=1;
	}
	for (;i<n;i+=2){
		cout<<a[i];
		if (i<n-1){
			cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}