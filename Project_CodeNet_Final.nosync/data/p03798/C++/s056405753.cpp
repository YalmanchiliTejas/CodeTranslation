#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

bool judge(string s, string t,int i,bool flag)
{
	int f = i+1;
	if(f>=t.length())
		f=0;
	int r = i-1;
	if(r<0) r = t.length()-1;
	if(s[i]=='o')
	{
		if(t[i]=='S' && t[f]!=t[r])
			flag = 0;
		else if(t[i]=='W' && t[f]==t[r])
			flag = 0;
	}
	else
	{
		if(t[i]=='S' && t[f]==t[r])
			flag = 0;
		else if(t[i]=='W' && t[f]!=t[r])
			flag = 0;
	}
	if(i==0)
		return flag;
	else
		return judge(s,t,0,flag);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t[4];
	t[0] += "SS";
	t[1] += "SW";
	t[2] += "WS";
	t[3] += "WW";
	for(int i = 1,j2=2; j2<s.length(); i++,j2++)
	{
		for(int j = 0; j<4; j++)
		{
			if(s[i]=='o')
			{
				if(t[j][i]=='S')
					t[j] += t[j][i-1];
				else
					t[j] += 'S'+'W'-t[j][i-1];
			}
			else 
			{
				if(t[j][i]=='W')
					t[j] += t[j][i-1];
				else
					t[j] += 'S'+'W'-t[j][i-1];
			}
		}
	}
	for(int i = 0; i<4; i++)
	{
	   // cout<<t[i]<<endl;
		if(judge(s,t[i],n-1,1))
		{
			cout<<t[i]<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}