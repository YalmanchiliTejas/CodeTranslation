#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,a[1000],i,count,j,s=0;
   cin>>n;
   for(i=0;i<n;i++)
        cin>>a[i];
   for(i=1;i<n;i++)
   {
       count=0;
        for(j=0;j<i;j++)
            if(a[i]>=a[j])
                count++;
        if(count==i)
            s++;
   }
   cout<<s+1<<endl;
    return 0;
}
