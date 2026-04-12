#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0,d=0,sum=0;
	char s[100];
	cin>>s;
	n = strlen(s);
	for(i=0; i<n; i++)
	{
		if(s[i]=='A')
        {
            c++;
        }
        else
        {
            d++;
        }
	}
	if(c>0 && d>0)
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
