#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pi  acos(-1)
const int w=2e5+5;
const ll mod=1e9+7;
int main()
{
    int i,j;
    string a;
    cin>>a;
    int ans1=0,ans2=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='A')
            ans1++;
        else
            ans2++;
    }
    if(ans1&&ans2)
        puts("Yes");
    else
        puts("No");
    return 0;
}
