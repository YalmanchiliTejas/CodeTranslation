#include<bits/stdc++.h>
using namespace std;
typedef       long long int      ll;
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       RESET(a, b)        memset(a, b, sizeof(a))
#define       gcd(a, b)          __gcd(a, b)
#define       MX                 200005
bool cmp(long long int x,long long int y)
{
   return x>y;
}
int main(void)
{
   long long int t,n,m,k,x,y,a[100001];
   vector<long long int> v,v1,v2;
   vector< pair <long long int,long long int> >p,p1,p2;
   set<long long int> st;
   priority_queue<long long int> pq;
   priority_queue< long long int,vector<long long int>,greater<long long int> > lpq;
   priority_queue< pair<long long int,long long int>,vector< pair<long long int,long long int> >,greater< pair <long long int,long long int> > > plpq;
   string s;
   //cin>>t;
   //while(t--)
   //{
      cin>>n;
      if(n>=30)
         cout<<"Yes"<<endl;
      else
         cout<<"No"<<endl;
   //}
   return 0;
}
