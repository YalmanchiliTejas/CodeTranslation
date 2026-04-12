#include <iostream>
using namespace std;

int A[3];
int main()
{	
	for(int i=0;i<3;i++)
		cin>>A[i];
		
	int c=A[1]*10+A[2];
	if(c%4==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
		
	// your code goes here
	return 0;
}