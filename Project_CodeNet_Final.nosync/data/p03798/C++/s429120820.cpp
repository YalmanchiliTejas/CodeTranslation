#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	cin>>n>>s;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		string t;
		t+=(i+'0');
		t+=(j+'0');
		for(int k=1;k<n-1;k++)
		{
			if(t[k]=='0')
			{
				if(s[k]=='o')
				t+=t[k-1];
				else
				t+=(t[k-1]=='0'?'1':'0');
			}
			else
			{
				if(s[k]=='x')
				t+=t[k-1];
				else
				t+=(t[k-1]=='0'?'1':'0');
			}
		}
		if(t[n-1]=='1')
		{
			if(s[n-1]=='o'&&t[0]=='0'&&t[n-2]=='1'||s[n-1]=='o'&&t[0]=='1'&&t[n-2]=='0')
			{
				if(t[0]=='0')
				{
					if(s[0]=='o'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='x'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
				else
				{
					if(s[0]=='x'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='o'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
			}
			if(s[n-1]=='x'&&t[0]=='1'&&t[n-2]=='1'||s[n-1]=='x'&&t[0]=='0'&&t[n-2]=='0')
			{
				if(t[0]=='0')
				{
					if(s[0]=='o'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='x'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
				else
				{
					if(s[0]=='x'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='o'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
			}
		}
		else
		{
			if(s[n-1]=='o'&&t[0]=='0'&&t[n-2]=='0'||s[n-1]=='o'&&t[0]=='1'&&t[n-2]=='1')
			{
				if(t[0]=='0')
				{
					if(s[0]=='o'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='x'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
				else
				{
					if(s[0]=='x'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='o'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
			}
			if(s[n-1]=='x'&&t[0]=='1'&&t[n-2]=='0'||s[n-1]=='x'&&t[0]=='0'&&t[n-2]=='1')
			{
				if(t[0]=='0')
				{
					if(s[0]=='o'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='x'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
				else
				{
					if(s[0]=='x'&&t[1]=='1'&&t[n-1]=='1'||s[0]=='x'&&t[1]=='0'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
					if(s[0]=='o'&&t[1]=='0'&&t[n-1]=='1'||s[0]=='o'&&t[1]=='1'&&t[n-1]=='0')
					{
						for(int i=0;i<n;i++)
						{
							if(t[i]=='0')
							cout<<"S";
							else
							cout<<"W"; 
						}
						return 0;
					}
				}
			}
		}
	}
	cout<<-1;
	return 0;
}