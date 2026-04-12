#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define mk make_pair
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define sf(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pf(a) printf("%d\n",a);
#define pfl(a) printf("%lld\n",a);
#define TEST int test; cin >> test;while(test--)
#define ii pair<int,int>
#define iil pair<ll,ll>
#define loop(i,a,b) for(int i = a ; i < b ; i++)
#define INF 2147483647


int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const double pi = acos(-1.0);

map<ll,ll>mp;
void solve()
{

   int n ;
   cin >> n;
   int a[n+10];
   int mn = -1, c= 0;
   for(int i = 0 ; i < n ; i++)
   {
     cin >> a[i];

     if(a[i] >= mn)
     {
       c++;
       mn = a[i];
     }

   }
   cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //TEST
    solve();
    return 0;
}
