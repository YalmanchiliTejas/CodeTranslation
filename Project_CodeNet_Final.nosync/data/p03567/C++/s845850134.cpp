#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char v[10];
	cin>>v;

	int s=strlen(v);

	for(int i=0; i<s-1; i++)
	{
		if(v[i]=='A' && v[i+1]=='C')
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}