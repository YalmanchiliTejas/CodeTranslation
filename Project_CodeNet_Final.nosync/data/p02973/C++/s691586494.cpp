#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
int a[N],f[N];
int ans;
int main()
{
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(f[ans]<=a[i])
        {
            f[++ans]=a[i];
        }
        else
        {
            f[upper_bound(f+1,f+1+ans,a[i])-f]=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
