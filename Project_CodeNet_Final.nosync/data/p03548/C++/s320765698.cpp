#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    int x,y,z;
    in x>>y>>z;
    bool flag=true;
    int i=1;
    while(flag){
        if(z+i*(y+z)<=x)i++;
        else flag=false;
    }
    cout<<i-1<<endl;
}
