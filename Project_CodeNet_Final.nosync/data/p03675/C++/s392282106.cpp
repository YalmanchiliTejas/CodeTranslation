#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int a,b,c,d,e,f,g,h,i,j;
     cin>>a;
     int ar[a];
     vector<int>v;
     vector<int>v1;
     for(i=0;i<a;i++)
     {
         cin>>c;
         if((i+1)%2==0)
         {
             v.push_back(c);
         }
         else{
            v1.push_back(c);
         }
     }
     if(a%2==0)
     {
     reverse(v.begin(),v.end());
         for(i=0;i<v.size();i++)
         {
             cout<<v[i]<<" ";
         }
         for(i=0;i<v1.size();i++)
         {
             cout<<v1[i]<<" ";
         }
        cout<<endl;
     }
     else{
     reverse(v1.begin(),v1.end());
        for(i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" ";
        }
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
     }
     return 0;
 }
