#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int r,g,b,a;
    cin>>r>>g>>b;
    a=r*100+g*10+b;
    if (a%4==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
