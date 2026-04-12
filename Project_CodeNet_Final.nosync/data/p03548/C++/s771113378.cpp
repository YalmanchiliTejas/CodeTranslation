#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>


using namespace std;



int main()
{
    int a,b,c,ans=0;
    cin>>a>>b>>c;
    a=a-c;
    ans=b+c;
    cout<<a/ans;

    return 0;
} 