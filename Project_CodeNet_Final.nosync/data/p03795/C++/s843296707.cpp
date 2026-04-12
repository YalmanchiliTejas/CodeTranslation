	/*     ####   ####  #               ####  #        ##   #    # #    # ###### #####
		  #      #    # #              #      #       #  #  ##  ## ##  ## #      #    #
		   ####  #    # #               ####  #      #    # # ## # # ## # #####  #    #
			   # #  # # #                   # #      ###### #    # #    # #      #####
		  #    # #   #  #              #    # #      #    # #    # #    # #      #   #
		   ####   ### # ###### #######  ####  ###### #    # #    # #    # ###### #    #
	*/
	 
	#include<bits/stdc++.h>
	using namespace std;
	 
	typedef long long LL;
	typedef vector<LL> VLL;
	typedef vector<string> VS;
	typedef vector<pair<LL, LL> > VP;
	 
	 
	#define For(in) for (LL i = 0; i < (n); i++)
	#define FOR(in) for(LL i=1; i <= (n); i++)
	#define pb push_back
	#define sr(v) sort(v.begin(), v.end())
	#define rev(v) reverse(v.begin(), v.end())
	#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end());
	#define exit(); return 0;
	#define no "NO"
	#define yes "YES"
	#define con continue;
	 
	 
	LL concate(LL a, LL b)
	{
		ostringstream os;
		os <<a <<b;
		istringstream is(os.str());
		LL c;
		is>> c;
		return c;
	}
	 
	 
	LL check(char c)
	{
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}
	 
	 
	int main()
	{
		LL q,t;
		//cin>>t;
		//while(t--)
		//{
		   LL a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,r=0,u=0,w=0,x=0,y=0,z=0;
			LL aa[1000];
			LL flag=0, flag1=0, co=0, co1=0, co2=0, co3=0, x1=0, x2=0, y1=0, y2=0, z1=0, z2=0;
			LL ma=0, mi=100000000;
			LL mid=0, temp=0, stop=0, start=0;
			double pi= 3.141592653589793;
			double d1=0.0, d2, d3, d4;
			VLL v,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
			VS vs, vs1, vs2, vs3, vs4;
			VP vp, vp1,vp2;
			char ch, ch1, ch2[1001];
			string str, str1, str2, str3, str4, str5;
			pair<LL, LL> pa;
			list<LL> li, li1;
			map<LL, LL> mp, mp1;
			set<LL> st;
			map<LL ,LL> :: iterator imll;
			VLL :: iterator ivll;
			set<LL> :: iterator isll;
			VP :: iterator ivp;
	 
			
			cin>>n;
			a = n/15;
			b = n*800;
			c = b-(a*200);
			cout<<c<<endl;
			
			
			
			
		 //}
	 
		exit()
	 
	 
	}
