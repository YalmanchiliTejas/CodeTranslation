#include<bits/stdc++.h>

using namespace std;

const int N=110;

int h,w;
char g[N][N];
bool vish[N],visw[N];

int main()
{
	cin>>h>>w;
	for(int i=1;i<=h;++i)
	{
		for(int j=1;j<=w;++j)
		{
			cin>>g[i][j];
			if(g[i][j]=='#')
			{
				vish[i]=true;
				visw[j]=true;
			}
		}
	}
	bool ok;
	for(int i=1;i<=h;++i)
	{
		ok=true;
		for(int j=1;j<=w;++j)
		{
			if(!vish[i]||!visw[j])continue;
			cout<<g[i][j];
			ok=false;
		}
		if(!ok)cout<<endl;
	}
	//for(int i=1;i<=h;++i){if(vish[i])cout<<"true"<<" ";else cout<<"false"<<" ";}
//	cout<<endl;
	//for(int i=1;i<=w;++i){if(visw[i])cout<<"true"<<" ";else cout<<"false"<<" ";}
	return 0;
}