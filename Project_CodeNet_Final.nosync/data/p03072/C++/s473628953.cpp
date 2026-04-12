#include <iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	int n,len=0,result=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		len=max(len,temp);
		if(temp>=len)
			result++;
	}
	cout<<result<<endl;
}