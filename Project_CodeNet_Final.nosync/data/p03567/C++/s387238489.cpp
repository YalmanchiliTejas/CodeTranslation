#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    char a[5];
    cin>>a;
    for(int i=0;i<5;i++)
    if(a[i]=='A'&&a[i+1]=='C')
    {cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl;
    return 0;
}