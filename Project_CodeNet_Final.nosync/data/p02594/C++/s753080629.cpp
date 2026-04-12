	/*
                            Author: Ankit Kaul
*******Code Belongs to Respective Author Only*************
*/
/*#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
/*freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
*/
#include <bits/stdc++.h>
#define endl       '\n'
#define PI          3.141592653589
#define jaldi       ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define M           1000000007
#define int         long long int
#define inf         INT_MAX
#define pb          emplace_back
#define pf          emplace_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
using namespace std;
int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b); }
int power(int x,int n){
    int result=1;
    while(n>0)
        {   if(n % 2 ==1)
            result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
    return result%M;
}
bool isPrime(int n)
    {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
    }
int inv(int a,int m)
{   return power(a,m-2);
}   
int lcm(int a,int b)
{   return a*b/(gcd(a,b));
}
signed main()
{   jaldi
    int x;
    cin>>x;
    if(x>=30)
    cout<<"Yes";
    else
    cout<<"No";
}

