#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof (a))
#define gcd(a,b) __gcd(a,b)
#define all(a) a.begin(),a.end()
#define in(a) insert(a)
#define sz() size()
#define endl '\n'
#define pb push_back
typedef unsigned long long ll;
const int maxn=100010;
const int inf=1e9;
const ll mod=998244353;
const double pi=3.14159265358979;
const double ep=0.0;
using namespace std;
int main()
{
    string s;
    int k,ans=0;
    cin>>s>>k;
    int n=s.sz();
    if (n>1)
    {
        if (k==1)
            ans+=(n-1)*9;
        else if (k==2)
            ans+=(n-1)*(n-2)/2*9*9;
        else
            ans+=(n-1)*(n-2)*(n-3)/6*9*9*9;
    }
    if (k==1)
        ans+=s[0]-'0';
    if (k==2)
    {
        ans+=(s[0]-'1')*(n-1)*9;
        s.erase(0,1);
        n--;
        while (s[0]=='0')
        {
            s.erase(0,1);
            n--;
        }
        if (n>=1)
        {
            ans+=(n-1)*9;
            ans+=(s[0]-'0');
        }
    }
    if (k==3)
    {
        ans+=(s[0]-'1')*(n-1)*(n-2)/2*9*9;
        s.erase(0,1);
        n--;
        while (s[0]=='0')
        {
            s.erase(0,1);
            n--;
        }
        if (n>1)
        {
            ans+=(n-1)*(n-2)/2*9*9;
            ans+=(s[0]-'1')*(n-1)*9;
            s.erase(0,1);
            n--;
            while (s[0]=='0')
            {
                s.erase(0,1);
                n--;
            }
            if (n>=1)
            {
                ans+=(n-1)*9;
                ans+=(s[0]-'0');
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
