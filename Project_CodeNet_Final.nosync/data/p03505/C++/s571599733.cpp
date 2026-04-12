#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
long long a,b,c;
int main()
{
	cin>>a>>b>>c;
	if(b>=a){cout<<1<<' '<<endl;return 0;}
	if(b<=c){cout<<-1<<endl;return 0;}
	if((a-b)%(b-c)==0)cout<<(a-b)/(b-c)*2+1<<endl;
	else cout<<a/(b-c)*2+1<<endl;
	return 0;
}