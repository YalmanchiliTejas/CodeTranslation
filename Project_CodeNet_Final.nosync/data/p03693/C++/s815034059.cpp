#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	puts((10*b+c)%4==0?"YES":"NO");
}
