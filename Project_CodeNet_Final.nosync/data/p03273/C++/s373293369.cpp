#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int h,w;
	cin >> h >> w;
	string a[h];

	for(int i=1;i<=h;i++)
		cin >> a[i-1];

	int h_black[105]={},w_black[105]={};

	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			if(a[i-1][j-1]=='#')
			{
				h_black[i-1]=1;
				w_black[j-1]=1;
			}
		}

	for(int i=1;i<=h;i++)
	{
		if(h_black[i-1]==1)
		{
			for(int j=1;j<=w;j++)
			{
				if(w_black[j-1]==1)
					cout << a[i-1][j-1];
			}
			cout << endl;
		}
	}
}
			
		