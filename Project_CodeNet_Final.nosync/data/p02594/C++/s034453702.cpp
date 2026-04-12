/*
Author: Hrujul Thumar
*/
#include <bits/stdc++.h>
#define int         long long
#define pb          push_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define whilet()    int t; scanf("%d",&t); while(t--)
#define vp          vector<pair<int,int>,int>
#define pb          push_back
#define mii         map<int,int>
#define pii         pair<int,int>
#define msi         map<string,int>
#define psi         pair<string,int>
#define mpi         map<pair<int,int>,int>
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define ef          else if
#define MOD         1000000007
#define endl        '\n'
#define fastio       ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define pi          3.141592653589793238
const long long MAX_SIZE = 1000000000;
using namespace std;
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int power(int x,  int y, int p){
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
            y = y>>1; // y = y/2
            x = (x*x) % p;
    }
    return res;
}

int mod_inv(int a,int m){
    a=a%m;
    return power(a,m-2,m)%MOD;
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

bool mod(double a,double b) {
    return a/b - floor(a/b);}

int logb(int base, int x) {
    return (log(x) / log(base));
}
char ToLower(char c)
{
    if ((c >= 'A') && (c <= 'Z')) return (char)((int)c - 'A' + 'a');
    else return c;
}

int Vowel(char c)
{
    c = ToLower(c);
    return (c == 'a') || (c == 'o') || (c == 'i') || (c == 'y') || (c == 'u') || (c == 'e');
}
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.first!=b.first)
    return a.first<b.first;
    return a.second>b.second;
}
int countSetBits(int x)
{
    if(x==0)return 0;
    else return 1+countSetBits(x&(x-1));
}
int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int n;
bool in_range(int x,int y)
{
    if(x>=0 && x<=n-1 && y>=0 && y<=n-1)return true;

    return false;
}
bool palindrom(string s)
{
    int len=s.length();
    bool okay=true;
    for(int i=0;i<=len/2;i++)
    {
        if(s[i]!=s[len-i-1]){okay=false; break;}
    }
    return okay;
}
signed main()
{
    fastio;
    int t;
    cin>>t;
    if(t>=30)cout<<"Yes"<<endl;
    else cout <<"No"<<endl;

}
