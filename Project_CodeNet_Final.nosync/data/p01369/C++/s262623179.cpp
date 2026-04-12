#include<iostream>
#include<string>
using namespace std;
int main()
{
	string left="qwertasdfgzxcvb";
	string in;
	while(cin>>in,in!="#") 
	{
		int ans=0;
		int pos=0;
		for(int i = 0; i < left.size(); ++i)
		{
			if(in[0]==left[i]) pos=1;
		}
		if(pos==0) pos=2;

		for(int i = 1; i < in.size(); ++i)
		{
			bool up=false;
			for(int j = 0; j < left.size(); ++j)
			{
				if(in[i]==left[j])
				{
					if(pos==2) ans++;
					pos=1;
					up=true;
					break;
				}
			}	
			if(!up)
			{
				if(pos==1) ans++;
				pos=2;
			}
		}
		cout<<ans<<endl;
	}

  return 0;
}