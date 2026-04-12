#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 10000
typedef long long ll;
using namespace std;
int main()
{
    char a[100];
    int flag=0;
    scanf("%s",a);
    for (int i=0;i<strlen(a);i++)
    {
        if (a[i]=='A'&&a[i+1]=='C')
          {
               flag=1;
               break;
          }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
