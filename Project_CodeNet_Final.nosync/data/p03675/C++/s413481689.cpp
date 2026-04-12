#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f=1;
int n,a[200010];
vector<int> b;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++)
		if(f) b.push_back(a[i]),f=0; else b.insert(b.begin(),a[i]),f=1;
	
	if(n%2==1) reverse(b.begin(),b.end());
	for(int i=0;i<b.size();i++) cout<<b[i]<<' ';
	
	return 0;
}