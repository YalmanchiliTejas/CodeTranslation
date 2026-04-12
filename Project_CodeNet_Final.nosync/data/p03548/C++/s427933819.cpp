#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int a,b,c;
    cin>>a>>b>>c;
    a-=c;
    cout<<a/(b+c);
    return 0;
}