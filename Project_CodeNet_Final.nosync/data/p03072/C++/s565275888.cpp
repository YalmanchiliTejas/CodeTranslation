#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,cnt=1,curr_max;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	curr_max=a[0];
	for(int i=1;i<n;i++)
	{
		curr_max=max(curr_max,a[i]);
		if((a[i]>=a[0])&&(a[i]>=curr_max)) cnt++;
	}
	cout<<cnt;
	return 0;
}