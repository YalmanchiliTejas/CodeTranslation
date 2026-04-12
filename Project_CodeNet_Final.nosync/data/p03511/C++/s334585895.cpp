#include<iostream>
#include<algorithm>
using namespace std;
int L;
string s,t;
main()
{
	cin>>L>>s>>t;
	if(L==s.size())
	{
		string ans=s;
		if(L%t.size()==0)
		{
			string tmp=t;
			while(tmp.size()<L)tmp+=t;
			if(ans>tmp)ans=tmp;
		}
		cout<<ans<<endl;
	}
	else if(L==t.size())
	{
		string ans=t;
		if(L%s.size()==0)
		{
			string tmp=s;
			while(tmp.size()<L)tmp+=s;
			if(ans>tmp)ans=tmp;
		}
		cout<<ans<<endl;
	}
	else
	{
		string ss=s,tt=t;
		while(ss.size()<L)ss+=s;
		while(tt.size()<L)tt+=t;
		if(ss>tt)swap(s,t);
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
}
