/*
    ____        __
   / __ \____  / /_  ____ _____ ___
  / /_/ / __ \/ __ \/ __ `/ __ `__ \
 / _, _/ /_/ / / / / /_/ / / / / / /
/_/ |_|\____/_/ /_/\__,_/_/ /_/ /_/
*/
#include<bits/stdc++.h>

typedef long long ll ;

#define X   first
#define Y   second
#define mp  make_pair
#define pii pair<int , int>
#define vec vector
#define vpii vector<pair<int , int>>
#define i_n   int i = 0 ; i< n ; i++
#define cn  int n ; cin>>n
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cina int a[n] ; for(int i = 0 ; i < n ; i++) cin>>a[i]
#define pb push_back
#define SZ(x) ll(x.size())

using namespace std;
const int maxn = 1000*100+5 ;

int main()
{
	migmig ;
	int n ;
	cin>>n ;
	int h[n] ; 
	int ans = 0 ; 
	for(int i = 0 ; i < n ; i ++)
	{
		cin>>h[i] ;
		bool b = true;  
		for(int j = i- 1 ; j >= 0 ; j--)
		{
			if(h[i] < h[j]) b = false ; 
		}
		if(b) ans++ ; 
	}
	cout<<ans; 
}
//////
////////
///////////

