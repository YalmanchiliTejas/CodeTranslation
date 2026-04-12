#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	x-=z*2;
	int cnt=x/(y+z);
	int ans=x-cnt*(y+z);
	cout<<cnt+(ans>=y);
}



