#include <bits/stdc++.h>
using namespace std;

 int main()
{
    vector <long long int> v,p;
   long long int x,n;
   cin>>n;
   for(int i=0; i<n; i++)
   {
       cin>>x;
       v.push_back(x);
   }

   int i;
   if(n%2==0)
   {
    for(int i=n-1; i>0; i-=2)
   {
       p.push_back(v[i]);
   }
        for(int i=0; i<n-1; i+=2)
    p.push_back(v[i]);

   }
   else
   {
    for(int i=n-1; i>=0; i-=2)
   {
       p.push_back(v[i]);
   }
        for(int i=1; i<n-1; i+=2)
    p.push_back(v[i]);

   }


 for(int i=0; i<p.size()-1; i++)
    cout<<p[i]<<" ";
 cout<<p[p.size()-1]<<endl;

}
