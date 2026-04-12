#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
#define maxx 110000
typedef long long ll;
string a;

int main()
{
    int k,n;
    cin>>n>>a>>k;
    char t = a[k-1];
    for(int i=0;i<n;i++)
    if(a[i]!=t) cout<<'*';
    else cout<<a[i];
    cout<<endl;
    return 0;
}