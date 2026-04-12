#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b , c , x , y ;
    cin>>a>>b>>c>>x>>y ;
    if(x == y)
     cout<<min(a*x + b * y , c*x*2);
    else if(x > y)
     cout<<min(a*x + b*y , min(c*x*2 , c*y*2 + a*(x-y)));
    else
     cout<<min(a*x + b*y , min(c*y*2 , c*x*2 + b*(y-x)));
    return 0 ;
}
