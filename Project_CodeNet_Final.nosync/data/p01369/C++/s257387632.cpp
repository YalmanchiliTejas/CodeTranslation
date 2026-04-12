#include<bits/stdc++.h>
using namespace std;

main(int argc, char const *argv[])
{
	string l="qwertasdfgzxcvb",r="yuiophjklnm",s;
	while(cin>>s,s!="#")
	{
		bool f=0;
		for (int i = 0; i < r.size(); ++i) if(s.at(0)==r.at(i)) f=1;
		int ans=0;
		for (int i = 1; i < s.size(); ++i)
		{
			if(f)
			{
				for (int j = 0; j < l.size(); ++j)
				{
					if(s.at(i)==l.at(j))
					{
						++ans,f=0;
						break;
					}
				}
			}
			else
			{
				for (int j = 0; j < r.size(); ++j)
				{
					if(s.at(i)==r.at(j))
					{
						++ans,f=1;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
