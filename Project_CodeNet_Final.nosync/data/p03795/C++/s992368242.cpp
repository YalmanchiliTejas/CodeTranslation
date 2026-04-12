#include<bits/stdc++.h>
#include<sstream>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(i=(int)a;i<(int)b;i++)
#define revloop(i,a,b) for(i=(int)a;i>=(int)b;i--)
#define stloop(it,v) for(it=v.begin();it!=v.end();++it)
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long int
#define PI acos(-1.0)
#define f first
#define s second
#define rs resize
int main()
{  std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin>>n;
   cout<<800*n - (n/15)*200;
   return 0;
}
