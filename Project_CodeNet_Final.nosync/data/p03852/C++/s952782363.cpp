#include<bits/stdc++.h>
using namespace std;
char a[5]={'a','e','i','o','u'},k;
int main()
{
    cin>>k;
    for(int i=0;i<=4;i++)
    {
    	if(k==a[i])
    	{
    		cout<<"vowel"<<endl;
    		return 0;
		}
	}
	cout<<"consonant"<<endl;
    return 0;
}