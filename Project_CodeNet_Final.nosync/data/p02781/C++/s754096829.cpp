//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back
#define inf 10000000000000000
#define N 1000000007
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
string str;int kd;
int n;
map<int,map<int,int>> mp;
map<int,map<int,bool>> done;
int f(int ix, int k)
{
	if(done[ix][k]){return mp[ix][k];}
	//cout<<ix<<" "<<k<<"\n";
	if(k<0){return 0;}
	if(ix==n-1)
	{
		int num=str[ix]-'0';
		if(k==1){
			if(num>0){return num;}
			else{return 0;}
		}
		if(k>1){return 0;}
		if(k==0)
		{
			return num==0;
		}
	}
	done[ix][k]=1;
	int num=str[ix]-'0';
	int tot=0;
	if(num>0){
		int rem=n-ix-1;
		//ix =0
		int numerator=1,den=1,p=1;
		for(int i=0;i<k;++i)
		{
			p*=9;
			numerator*=rem-i;
			den*=i+1;
		}
		tot+=((numerator/den)*p);
		//ix<maxi
		if(k-1>=0)
		{
			numerator=1;den=1;p=1;
			for(int i=0;i<k-1;++i)
			{
				p*=9;
				numerator*=rem-i;
				den*=i+1;
			}
			tot+=(num-1)*((numerator/den)*p);
		}
		
		//ix=maxi
		tot+=f(ix+1,k-1);
	}
	else
	{
		tot+=f(ix+1,k);
	}
	//cout<<ix<<' '<<k<<' '<<tot<<"\n";
	mp[ix][k]=tot;
	return tot;


}
signed main()
{
	speed
	cin>>str>>kd;
	n=str.length();
	cout<<f(0,kd);

}