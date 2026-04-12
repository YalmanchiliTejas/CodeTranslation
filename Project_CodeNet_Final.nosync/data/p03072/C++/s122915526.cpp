#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<ll, ll>& a, pair<ll, ll>& b)
{
  if(a.first == b.first)
  {
    return a.second < b.second;
  }
  return a.first > b.first;
}

int main()
{
 ll q,n, r, avg, i, j, c;
 while(cin >> n)
 {
   ll a[n + 5];
   map<pair<ll, ll> , ll> m;
   map<ll, ll>::iterator it;
   for(i = 0; i < n; i++)
   {
     cin >> a[i];
   }
   c = 1,j = a[0];
   for(i = 1; i < n; i++)
   {
     if(a[i] >= j){
       j = a[i];
       c++;
     }
   }
   cout << c << endl;
   
 }
 return 0;
}