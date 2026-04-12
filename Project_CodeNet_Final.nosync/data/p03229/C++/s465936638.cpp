#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n=0;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   int b[n];
   sort(a,a+n);
   int k[n];
       b[0]=a[n/2];
       k[0]=a[n/2];
       int c=0;
       int i=0,j=n-1;
       while(c<n-1){
           c++;
           if(c%2!=0)
           b[c]=a[i++];
           else
           b[c]=a[j--];
          // cout<<"i="<<i<<endl;
           //cout<<"j="<<j<<endl;
           }
    i=0;j=n-1;c=0;
           while(c<n-1){
           c++;
           if(c%2==0)
           k[c]=a[i++];
           else
           k[c]=a[j--];
           }

       //for(int i=0;i<n;i++)
      //  cout<<b[i]<<" ";
       long long int sum1=0,sum2=0;
       for(int i=0;i<n-1;i++)
        sum1=sum1+abs(b[i]-b[i+1]);
        for(int i=0;i<n-1;i++)
        sum2=sum2+abs(k[i]-k[i+1]);
        cout<<max(sum1,sum2)<<endl;
}
