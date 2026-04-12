#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int x,y,z;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    
	cin>>x>>y>>z;
	x-=z;
	cout<<x/(y+z);
}
	