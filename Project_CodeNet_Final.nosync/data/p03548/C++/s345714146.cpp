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

int a,b,c;
int main()
{
	cin>>a>>b>>c;
	a-=c;
	cout<<a/(b+c)<<endl;
}