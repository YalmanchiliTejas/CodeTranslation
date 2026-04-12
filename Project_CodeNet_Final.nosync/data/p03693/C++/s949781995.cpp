#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

int main()
{
   int r,g,b;
   cin>>r>>g>>b;
   (100*r+10*g+b)%4==0?cout<<"YES":cout<<"NO";
   cout<<endl;
   return 0;
}