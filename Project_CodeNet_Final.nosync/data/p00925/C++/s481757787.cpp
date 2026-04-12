#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll leftrule(string s)
{
	ll ret=0;
	int i=0;
	if(s.size()==1)
		return s[0]-'0';
	
	ret=s[0]-'0';
	i++;
	while(i<s.size())
	{
		if(s[i]=='+')
		{
			ret+=(s[i+1]-'0');
			i+=2;
		}else{
			ret*=(s[i+1]-'0');
			i+=2;
		}
	}
	return ret;
}

ll multirule(string s)
{
	vector<ll> num;
	vector<bool> op;
	ll ret=0;
	if(s.size()==1)
		return s[0]-'0';
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+')
			op.push_back(false);
		else if(s[i]=='*')
			op.push_back(true);
		else
			num.push_back(s[i]-'0');
	}
	int j=0;
	ret=num[0];
	for(int i=1;i<num.size();i++)
	{
		if(op[j])
		{
			ret*=num[i];
			j++;
		}else{
			j++;
			ll tmp=num[i];
			while(op[j])
			{
				if(j==op.size())
					break;
				i++;
				tmp*=num[i];
				j++;
			}
			ret+=tmp;
		}
	}
	return ret;
}

int main()
{
	string s;
	string ss="ILMU";
	ll a;
	int ans=0;
	cin>>s;
	cin>>a;
	ll l=leftrule(s);
	//cerr<<l<<endl;
	ll m=multirule(s);
	//cerr<<m<<endl;
	if(a==l)
		ans+=1;
	if(a==m)
		ans+=2;
	cout<<ss[ans]<<endl;
	return 0;
}
