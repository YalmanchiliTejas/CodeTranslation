#include<bits/stdc++.h>

using namespace std;

int main()
{
	int q,w[20],e=1,t;
	cin>>q;
	for(int r=1;r<=q;r++)  cin>>w[r];
    t=w[1];	
    for(int r=2;r<=q;r++)
	if(w[r]>=t)  
	{
	t=w[r];
	e++;
	}
	
	
	cout<<e;
	
}