#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int n;
string s;
int a[27];
int minn[51];

int main()
{
   	cin>>n;
	for(int i=1;i<=26;i++)minn[i]=10086;
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=26;j++)a[j]=0;
        cin>>s;
        for(auto j:s)a[j-'a'+1]++;
		for(int j=1;j<=26;j++)minn[j]=min(minn[j],a[j]);
    }
    for(int i=1;i<=26;i++)
		for(int j=1;j<=minn[i];j++)putchar('a'+i-1);
}