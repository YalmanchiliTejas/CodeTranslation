# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <math.h>
# include <algorithm>
using namespace std;
# define pi acos(-1.0)
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((c+b*10+a*100)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}



















