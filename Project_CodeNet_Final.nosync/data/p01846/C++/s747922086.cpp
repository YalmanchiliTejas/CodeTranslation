#include "bits/stdc++.h"
using namespace std;

string board[10];

//jfenを元の記号列に戻す
string decode(string in)
{
	string ret;
	for(int i=0;i<in.size();i++)
	{
		if(in[i]=='b')
			ret+='b';
		else{
			int n=in[i]-'0';
			for(int j=0;j<n;j++)
				ret+='.';
		}
	}
	return ret;
}

//記号列をjfenに直す
string encode(string in)
{
	string ret;
	int ind=0;
	while(ind<in.size())
	{
		//cerr<<ind<<endl;
		if(in[ind]=='b')
		{
			ret+='b';
			ind++;
		}else{
			int cnt=0;
			while(ind<in.size() && in[ind]=='.')
			{
				cnt++;
				ind++;
			}
			ret+=(char)('0'+cnt);
		}
	}
	return ret;
}

int main()
{
	while(1)
	{
		string s;
		cin>>s;
		if(s[0]=='#')
			break;
		for(int i=0;i<10;i++)
			board[i].clear();
		//行ごとに分解
		int i=0;
		int h=0;
		string tmp;
		while(i<s.size())
		{
			if(s[i]!='/')
				tmp+=s[i];
			else{
				board[h]=tmp;
				h++;
				tmp.clear();
			}
			i++;
		}
		board[h]=tmp;
		h++;
		//cerr<<h<<endl;
		for(int i=0;i<h;i++)
		{
			board[i]=decode(board[i]);
			//cerr<<board[i]<<endl;
		}
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;b--;c--;d--;
		board[c][d]='b';
		board[a][b]='.';
		string ans;
		for(int i=0;i<h;i++)
		{
			//cerr<<board[i]<<endl;
			ans+=encode(board[i]);
			if(i<h-1)
				ans+='/';
		}
		cout<<ans<<endl;
	}
	return 0;
}
