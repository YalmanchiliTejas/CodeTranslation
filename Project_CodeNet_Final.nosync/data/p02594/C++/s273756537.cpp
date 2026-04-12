#include<bits/stdc++.h>
using namespace std;

void go()
{
#ifndef ONLINE_JUDGE
  freopen("inn.txt","r",stdin);
  freopen("o.txt","w",stdout);
  #endif
}


int main()
{
	go();
	int n;cin>>n;
	if(n>=30)
		cout << "Yes" <<"\n";
	else
		cout << "No" <<"\n";
}