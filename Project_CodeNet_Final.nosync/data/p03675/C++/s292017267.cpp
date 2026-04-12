#include<iostream>
#include<deque>
#define LL long long 
using namespace std;
deque<int> b;
deque<int>::iterator it;
int a[200010],c[200010];
int main()
{
   int n,i;
   cin>>n;
   for (i=1;i<=n;i++)
   {
       c[i]=(n-i)%2;
       cin>>a[i];
   }

   for (i=1;i<=n;i++)
   {
       if (c[i]) b.push_back(a[i]);
       else b.push_front(a[i]);
   }
   for (it=b.begin();it!=b.end();it++)
       cout<<*it<<' ';
   cout<<endl;
}
