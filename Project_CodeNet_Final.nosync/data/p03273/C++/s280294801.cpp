
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	#define MAXN 102
	using namespace std;
	 char arr[MAXN][MAXN];
	 int n,m;
	 bool cr[MAXN];
	 bool cc[MAXN];
  void checkr(int i){
    for (int j = 0; j <((m==1)?1:(m-1)); ++j)
     {
       if(arr[i][j]!=arr[i][j+1]||arr[i][j]=='#'){
         cr[i]=false;
         goto noob;
    }
     } 
     // true if ......
       cr[i]=true;
        noob:;
  }

  void checkc(int j){
  for (int i = 0; i <((n==1)?1:(n-1)); ++i)
     {
       if(arr[i][j]!=arr[i+1][j]||arr[i][j]=='#'){
        
          cc[j]=false;
           goto noob;
     } }
        cc[j]=true;
        noob:;

        
  }
  
	int main()
	{
		
		std::ios::sync_with_stdio(false);
		 cin.tie(0);
		 cout.tie(0);
		
		cin>>n>>m;


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
			   cin>>arr[i][j];
			}
		}


     


		for (int i = 0; i < n; ++i)
		{
			checkr(i);
		}
		for (int j = 0; j < m; ++j)
		{
			checkc(j);
		}
          
        for (int i = 0; i < n; ++i)
            {
            	
            	for (int j = 0; j <m ; ++j)
            	{
            		if(cr[i]==true||cc[j]==true){
                    arr[i][j]='*';
                                   		}
            		
            	}
          
            }    
            bool flag=0;
             for (int i = 0; i < n; ++i)
            {
            	flag=0;
            	for (int j = 0; j <m ; ++j)
            	{
                 if(arr[i][j]!='*'){
                 	cout<<arr[i][j];
                    flag=1;
                 }  
                 }
                if(flag)cout<<endl;

             }
         

		
		return 0;
	}
