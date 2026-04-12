#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

int i,n;
string str;
int main()
{
cin>>str;
n=str.length();
for(i=0;i<n;i++)
{
	if(str[i]=='A'&&str[i+1]=='C')
	{
		cout<<"Yes"<<endl;
		return 0;
	}
}
cout<<"No"<<endl;
 return 0;
}