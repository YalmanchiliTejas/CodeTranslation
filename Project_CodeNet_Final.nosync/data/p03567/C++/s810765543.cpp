#include<iostream>
#include<string>
#include<algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long LL;

const int MAX = 1000;

int main()
{
    char a[100];
    cin>>a;
    int len = strlen(a);
    for(int i = 0;i<len;i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
              cout<<"Yes"<<endl;
              return 0;
        }

    }

    cout<<"No"<<endl;

    return 0;
}
