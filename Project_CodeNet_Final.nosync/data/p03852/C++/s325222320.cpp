#include<bits/stdc++.h>
using namespace std;
char s,a[5]={'a','e','i','o','u'};
int main()
{
    cin>>s;
    for(int i=0;i<5;i++)
	{
        if(s==a[i])
		{
            cout<<"vowel"<<endl;
        	return 0;
		}
	}
    cout<<"consonant"<<endl;
	return 0;
}