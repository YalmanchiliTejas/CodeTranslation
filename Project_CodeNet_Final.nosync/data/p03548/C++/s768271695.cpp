#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a,b,c;
int check(int x,int y,int z)
{
	int ans;
	x-=z;
	ans=x/(y+z);
	return ans;
}
int main()
{
    cin>>a>>b>>c;
    cout<<check(a,b,c)<<endl;

    return 0;
}