#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define endl "\n"
#define print_array(name,n) for(ll o=0;o<n;o++) cout<<name[o]<<" "
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 2e18
#define pll pair<ll,ll>
#define pii pair<int,int>
bool sortbysecond(const pair<int,int> &a,const pair<int,int> &b){
	return (a.ss>b.ss);
}
 
ll gcd(ll a,ll b){ if(b==0) return a; return gcd(b,a%b) ;} 

template <typename T>
string NumberTostring(T Number )
{
	ostringstream ss;
	ss<<Number;
	return ss.str();
}
 

 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 	ll x;
 	cin>>x;
 	if(x>=30){
 		cout<<"Yes"<<endl;
 	}   
 	else{
 		cout<<"No"<<endl;
 	}
    return 0;
}