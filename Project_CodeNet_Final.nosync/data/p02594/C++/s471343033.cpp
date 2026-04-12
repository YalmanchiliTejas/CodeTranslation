/* 

Author: Vishal Singh  
(singhvishal0304@gmail.com)

"The days that break you are the days that make you."

*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);\
cin.tie(NULL);

#define md 1000000007


#define lli long long int
#define pb push_back
#define mp make_pair
#define vvi(r,c) vector<vector<lli>> v(r,vector<lli>(c));
#define fi first
#define se second
#define mem(arr,x) memset(arr,x,sizeof(arr))

lli power(lli a,lli b){
	if(b==0)
		return 1;
	if(b%2)
		return ((a%md)*(power(a,b-1)))%md;
	else
	{
		lli x=power(a,b/2);
		return (x*x)%md;
	}
}

void solve(){
	int c;
	cin>>c;
	if(c>=30)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}


int main()
{	
    fastio();
	int t;
	
	t=1;
	while(t--){
		solve();
	}

	return 0;
}