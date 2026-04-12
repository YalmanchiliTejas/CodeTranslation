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
   int n;
   while(cin>>n,n){
       vector<int> data;
       rep(i,n){
           int temp;
           cin>>temp;
           data.push_back(temp);
       }
       SORT(data);
       long ans=0;
       REP(i,1,n-1){
           ans+=data[i];
       }
       cout<<ans/(n-2)<<endl;;
   }
   return 0;
}