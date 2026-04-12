#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int cnt=0;
    for (int i=1;i<=a;i++) 
	{
        getchar();
        for (int j=1;j<=b;j++)
	    {
            char ch=getchar();
            if (ch=='#') 
			     cnt++;
        }
    }
    puts ((cnt==a+b-1)?"Possible":"Impossible");
    return 0;
}