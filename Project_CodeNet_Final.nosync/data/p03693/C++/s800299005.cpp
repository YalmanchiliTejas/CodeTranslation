#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d=a*100+b*10+c;
    if(d%4==0) printf("YES");
    else printf("NO");
    return 0;
}
