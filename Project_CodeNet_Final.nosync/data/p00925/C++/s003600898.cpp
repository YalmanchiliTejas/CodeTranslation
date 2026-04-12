#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main() 
{
	//入力
	string s;cin>>s;
	ll ans;cin>>ans;
	
	//まずはかけ算
	ll ans1(0);
	int tmp(1);
	
	if(s.length()==1)
	{
		ans1=s[0]-'0';
	}
	else
	{
		for(int i=0;i<(s.length())/2;i++)
		{
			if(i==0)
			{
				if(s[i*2+1]=='+')
				{
					ans1+=s[i*2]-'0';
					if(i==(-3+s.length())/2)
				{
					ans1+=s[i*2+2]-'0';
				}
			}
			else
			{
				tmp*=s[i*2]-'0';
				if(i==(-3+s.length())/2)
				{
					tmp*=s[i*2+2]-'0';
					ans1+=tmp;
				}
			}
		}
		else
		{
			if(s[i*2+1]=='+')
			{
				if(s[i*2-1]=='*')
				{
					tmp*=s[i*2]-'0';
					ans1+=tmp;tmp=1;
					if(i==(-3+s.length())/2)
					{
						ans1+=s[i*2+2]-'0';
					}
				}
				else
				{
					ans1+=s[i*2]-'0';
					if(i==(-3+s.length())/2)
					{
						ans1+=s[i*2+2]-'0';
					}
				}
			}
			else
			{
				tmp*=s[i*2]-'0';
				if(i==(-3+s.length())/2)
				{
					tmp*=s[i*2+2]-'0';
					ans1+=tmp;
				}
			}
		}}
	}
		//足し算
	ll ans2(0);
	if(s.length()==1)
	{
		ans2+=s[0]-'0';
	}
	else
	{
		for(int i=0;i<(s.length())/2;i++)
		{
			if(i==0)
			{
				if(s[i*2+1]=='+')
				{
					ans2+=s[i*2]-'0'+s[i*2+2]-'0';//cout<<"-1-"<<" "<<ans2<<endl;
				}
				else
				{
					ans2+=(s[i*2]-'0')*(s[i*2+2]-'0');//cout<<"-2-"<<" "<<ans2<<endl;
				}
			}
			else
			{
				if(s[i*2+1]=='+')
				{
					ans2+=s[i*2+2]-'0';//cout<<"-3-"<<" "<<ans2<<endl;
				}
				else
				{
					ans2*=s[i*2+2]-'0';//cout<<"-4-"<<" "<<ans2<<endl;
				}
			}
		}
	}
	
	bool m =(ans==ans1);
	bool l =(ans==ans2);
		
	if(m&&!l){cout<<'M'<<endl;}
	if(!m&&l){cout<<'L'<<endl;}
	if(m&&l){cout<<'U'<<endl;}
	if(!m&&!l){cout<<'I'<<endl;}
	
	return 0;
}