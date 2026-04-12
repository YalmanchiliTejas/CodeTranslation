//#include    <bits/stdc++.h>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
#define N  100005
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f
template<typename T> inline T max(T a,T b,T c){
    return max(a,max(b,c));
}
template<typename T> inline T min(T a,T b,T c){
    return min(a,min(b,c));
}
template<typename T> inline T max(T a,T b,T c,T d){
    return max(a,max(b,c,d));
}
template<typename T> inline T min(T a,T b,T c,T d){
    return min(a,min(b,c,d));
}
const int  dx[]={0,1,0,-1,0,1,-1,1,-1};
const int  dy[]={0,0,1,0,-1,1,-1,-1,1};
typedef long long ll;
using namespace std;
//coding...........................
int parent[N];
struct coordinate
{
    int x;
    int y;
    int id;
}a[N];
struct point
{
    int start;
    int ending;
    int cost;
}b[N*4];

int cmp1(coordinate n,coordinate m)
{
    return n.x<m.x;
}
int cmp2(coordinate n,coordinate m)
{
    return n.y<m.y;
}
int cmp3(point n,point m)
{
    return n.cost<m.cost;
}
int Find(int x)
{
    if(parent[x]==x)
      return x;
    else
      return parent[x]=Find(parent[x]);

}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
       {
           cin>>a[i].x>>a[i].y;
           a[i].id=i;
       }
     sort(a+1,a+1+n,cmp1);
     int k=0;
     for (int i=1;i<n;i++)
     {
         b[k].start=a[i].id;
         b[k].ending=a[i+1].id;
         b[k].cost=abs(a[i+1].x-a[i].x);
         k++;
     }
     sort(a+1,a+1+n,cmp2);
     for (int i=1;i<n;i++)
     {
         b[k].start=a[i].id;
         b[k].ending=a[i+1].id;
         b[k].cost=abs(a[i+1].y-a[i].y);
         k++;
     }
     sort(b,b+k,cmp3);
     for (int i=1;i<=n;i++)
        parent[i]=i;
     ll ans=0;
     for (int i=0;i<k;i++)
     {
         int w=Find(b[i].start);
         int v=Find(b[i].ending);
         if (w!=v)
         {
             ans+=b[i].cost;
             parent[w]=v;
         }
     }
     cout << ans << endl;
    return 0;
}
