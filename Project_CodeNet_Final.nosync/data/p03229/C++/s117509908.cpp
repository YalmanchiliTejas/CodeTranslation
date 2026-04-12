#include <queue>
#include <vector>
#include <algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e9
#define eps 1e-6
#define PI acos(-1.0)
#define M 10010
typedef pair<int, int>P;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int n;
ll a[maxn];

int main()
{
   cin >> n ;
   for(int i = 0 ; i < n ; i++)
   cin  >> a[i];
   if(n == 2 )
   {
       cout << abs(a[0] - a[1]) << endl;
       return 0;
   }
   sort(a,a+n);
   deque<ll> q;
   q.push_back(a[n-1]);
   q.push_back(a[0]);
   q.push_back(a[n-2]);
   int st = 1, ed = n-3;
   int tot = 0;
   while(1){
      if(!tot){
         if(st <= ed) {
                q.push_front(a[st]);
                st++;
          }
         if(st <= ed) {
                q.push_back(a[st]);
                st++;
          }
      }
      else {
         if(ed >= st ) {
              q.push_front(a[ed]);
              ed --;
         }
        if(ed >= st ) {
              q.push_back(a[ed]);
              ed --;
         }
      }
      tot = (tot + 1) %2 ;
      if(st > ed) break;
    }
    ll ans1 = 0;
    for(int i = 0;i< q.size() - 1; i++)
        ans1 += abs(q[i] - q[i+1]);

   deque<ll> d;
   d.push_back(a[0]);
   d.push_back(a[n-1]);
   d.push_back(a[1]);
   st = 2, ed = n-2;
   tot = 0;
   while(1){
      if(tot){
         if(st <= ed) {
                d.push_front(a[st]);
                st++;
          }
         if(st <= ed) {
                d.push_back(a[st]);
                st++;
          }
      }
      else {
         if(ed >= st ) {
              d.push_front(a[ed]);
              ed --;
         }
        if(ed >= st ) {
              d.push_back(a[ed]);
              ed --;
         }
      }
      tot = (tot + 1) %2 ;
      if(st > ed) break;
    }
    ll ans2 = 0;
    for(int i = 0;i< d.size() - 1; i++)
        ans2 += abs(d[i] - d[i+1]);

    cout << max(ans1,ans2)<<endl;
    return 0;
}
