#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES
 
// long long binpow(long long a,long long b)
// {
//     if (b == 1) return a;
//     long long res = binpow(a, b/2)%MOD;
//     if (b % 2) return (res*((res*a)%MOD))%MOD;
//     else return (res * res)%MOD;
// }
 
// long long int fact(long long int a)
// {
//     if(a==0||a==1)
//         return 1;
//     long long int ans = 1;
//     for(int i=a;i>=1;i--)
//         ans = (ans * i);
//     return ans;
// }
 
// long long int ivmod(long long int a)
// {
//     return binpow(a,MOD-2);
// }
 
// long long int ncr(long long int a,long long int b)
// {
//     long long int pans=1;
//     for(int i =a;i>max(b,a-b);i--)
//         pans=pans*i;
//     long long int div = fact(min(b,a-b));
//     // cout<<ans<<"            "<<div<<endl;
//     pans = pans/div;
//     return pans;
// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    map<char,int> mm;
    char arr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        if(i==0)
        {
            for(int j=0;j<26;j++)
                mm[arr[j]]=0;
            for(int j=0;j<a.length();j++)
            {
                mm[a[j]]++;
            }
        }
        else
        {
            map<char,int> mmt;
            for(int j=0;j<26;j++)
                mmt[arr[j]]=0;
            for(int j=0;j<a.length();j++)
            {
                mmt[a[j]]++;
            }
            map<char,int>::iterator itt = mmt.begin();
            for(map<char,int>::iterator it = mm.begin();it!=mm.end();it++)
            {
                it->second = min(it->second,itt->second);
                // cout<<itt->second<<"        "<<it->second<<"    "<<it->first<<endl;
                itt++;
            }
        }
    }
    int c = 0;
    for(map<char,int>::iterator it = mm.begin();it!=mm.end();it++)
    {
        int temp = it->second;
        for(int i=0;i<temp;i++)
        {
            cout<<arr[c];
        }
        c++;
    }
    cout<<endl;
    return 0;
}