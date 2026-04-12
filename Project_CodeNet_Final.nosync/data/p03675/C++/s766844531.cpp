#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a[200005],j,i,n;
	cin >> n;
	for(i=0; i<n; i++)
		cin >> a[i];
	for(i=n-1; i>=0; i-=2)
		cout << a[i] <<" ";
	if(i==-2) i=0;
	for(j=i+1; j<n; j+=2)
		cout << a[j] << " ";
}
