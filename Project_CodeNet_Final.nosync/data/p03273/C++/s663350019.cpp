#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x,y;
string a[105];
set<int> r,c;
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++)
            cin>>a[i];
     for(int i=0;i<x;i++){
            bool f=0;
        for(int j=0;j<y;j++)
        {
            if(a[i][j]=='#')
            {
                f=1;
                break;
            }
        }
        if(f==0)
            {
                r.insert(i);
            }
     }
      for(int i=0;i<y;i++){
            bool f=0;
        for(int j=0;j<x;j++)
        {
            if(a[j][i]=='#')
            {
                f=1;
                break;
            }
        }
        if(f==0)
            {
                c.insert(i);
            }
     }
     for(int i=0;i<x;i++){
           bool f=0;
        for(int j=0;j<y;j++)
     {
         if(r.count(i)||c.count(j))
            continue;
         else
         {
             cout<<a[i][j];
             f=1;
         }

     }
     if(f)
     cout<<endl;
     }
}