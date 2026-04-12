#include <iostream>
using namespace std;
char s[11];
int main()
{
	int n,k;
	cin>>n;
	for (int i=1;i<=n;i++)  cin>>s[i];
	cin>>k;
	char dtn=s[k];
	for (int i=1;i<=n;i++)
	{
		if (s[i]!=dtn)  s[i]='*';
	}
	for (int i=1;i<=n;i++)  cout<<s[i];
	return 0;	
}