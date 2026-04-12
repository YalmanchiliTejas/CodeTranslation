#include <bits/stdc++.h>
using namespace std;

int main()
{
  	int width,interval,gap;
  	cin>>width>>interval>>gap;
  	width-=gap;
  	cout<<width/(interval+gap)<<endl;
	return 0;
}