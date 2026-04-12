#include <iostream>
#include <string> 
#include <stdio.h>
using namespace std; 
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define ll long long int
#define REPI(a, b, i, inc) for(ll i = a; i < b; i = i + inc)
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define F first
#define S second
#define pb push_back
#define test ll t; cin>>t; while(t--)
#define testi ll t; cin>>t; REP(tc,1,t+1)
#define vec vector
#define veci vector<ll>
#define pi pair<ll,ll>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define uset unordered_set
#define umap unordered_map

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    int n;
    cin>>n;
	if(n>=30)
      cout<<"Yes";
  else
  	    cout<<"No";

	


	
	return 0;


}