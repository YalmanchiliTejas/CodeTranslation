#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
#include<set>
#include<vector>
#include<cmath>
#include<ctime>
#include<locale>
using namespace std;
int main()
{
    long a,b,c;
    cin>>a>>b>>c;
    c=c+a*100+b*10;
    if(c%4==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}
