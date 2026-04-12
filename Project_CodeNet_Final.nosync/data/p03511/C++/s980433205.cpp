#include<iostream>
#include<algorithm>
using namespace std;
int L;
string s,t;
main()
{
	cin>>L>>s>>t;
	if(s+t>t+s)swap(s,t);
	for(int i=L/s.size();;i--)
	{
		if((L-s.size()*i)%t.size()==0)
		{
			string ans="";
			for(int j=0;j<i;j++)ans+=s;
			while(ans.size()<L)ans+=t;
			cout<<ans<<endl;
			return 0;
		}
	}
}