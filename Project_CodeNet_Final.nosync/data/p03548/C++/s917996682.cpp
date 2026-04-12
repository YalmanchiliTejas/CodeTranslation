#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define N 100100
typedef long long ll;
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
   int ans=x/y;
       while (x-ans*y<(ans+1)*z)
            ans--;
            cout << ans << endl;


    return 0;
}
