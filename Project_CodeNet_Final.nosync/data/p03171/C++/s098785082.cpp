#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const ll INF = 1e9;
inline ll read(){
    ll X = 0,w = 0 ;
    char ch = 0;
    while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
    while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
    return w ? -X : X;
}

ll dat[10005];
ll dp[3005][3005];
int main()
{
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=0;i<n;++i)
    {
        cin>>dat[i];
        sum+=dat[i];
    }
    ll len=0;
    if(n%2==1) 
    {
        for(ll i=0;i<n;++i)
        {
            dp[i][i]=dat[i];
        }
        len=2;
    }
    else
    {
        for(ll i=0;i<n-1;++i)
        {
            dp[i][i+1]=max(dat[i],dat[i+1])-min(dat[i],dat[i+1]);
        }
        len=3;
    }
    while(len<n)
    {
        for(ll i=0;i+len<n;++i)
        {
            dp[i][i+len]=max(min(dat[i]-dat[i+1]+dp[i+2][i+len],dat[i]-dat[i+len]+dp[i+1][i+len-1]),min(dat[i+len]-dat[i+len-1]+dp[i][i+len-2],dat[i+len]-dat[i]+dp[i+1][i+len-1]));
        }   
        len+=2;
    }
    cout<<(sum+dp[0][n-1])/2-(sum-dp[0][n-1])/2<<endl;
    return 0;
}