#include<bits/stdc++.h>

using namespace std;
	
const int maxn=1e5;
int b[maxn];

int main()
{
	int a,c,d=0;
	cin >> a >> c;
	string s[a];
	for(int i=0;i<a;i++)
	{
		cin >> s[i];
		for(int j=0;j<c;j++)
			if(s[i][j] == '#')
				d++;
	}
	if(d==a+c-1)
		cout << "Possible";
	else cout << "Impossible";
}

 

