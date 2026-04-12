#include <iostream>
using namespace std;

int main()
{
	int h, w;
	int cnt = 0;
	char c;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>c;
			if(c == '#') ++cnt;
		}
	}
	if(cnt == h + w - 1) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	//getchar();getchar();
	return 0;
}