#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main()
{
   int n;
   vector <int> a;
   int ans[100005];
   int a_temp;
   long long int answer=0;
   long long int answer_temp=0;
   cin >> n;
   
   
   
   for (int i=0;i<n;i++)
   {
       
       cin >>a_temp;
       a.push_back(a_temp);
       
   }
   
   sort(a.begin(),a.end());
   
   
   if (n==1)
   {
       cout << a[0]<<endl;
       return 0;
   }
   if (n%2==1)
   {
       int cnt =n-1;
       
       for (int i=1;i<n;i=i+2)
       {
           
           ans[i]=a[cnt];
           cnt-=1;
          
       }
       ans[0]=a[cnt];
       cnt-=1;
       ans[n-1]=a[cnt];
       cnt-=1;
       for (int i=2;i<n-1;i=i+2)
       {
           ans[i]=a[cnt];
           cnt-=1;
           
       }
       for(int i=0;i<n-1;i++)
       {
       answer+=abs(ans[i]-ans[i+1]);
       
       }
       
        cnt =0;
       
       for (int i=1;i<n;i=i+2)
       {
           
           ans[i]=a[cnt];
           cnt+=1;
          
       }
       ans[0]=a[cnt];
       cnt+=1;
       ans[n-1]=a[cnt];
       cnt+=1;
       for (int i=2;i<n-1;i=i+2)
       {
           ans[i]=a[cnt];
           cnt+=1;
           
       }
       
        for(int i=0;i<n-1;i++)
       {
       answer_temp+=abs(ans[i]-ans[i+1]);
       
       }
       
       answer=max(answer,answer_temp);
       
   }
   else
   {
       int cnt =n-1;
       
       for (int i=1;i<n;i=i+2)
       {
           
           ans[i]=a[cnt];
           cnt-=1;
          
       }
      
       for (int i=0;i<n;i=i+2)
       {
           ans[i]=a[cnt];
           cnt-=1;
           
       }
       for(int i=0;i<n-1;i++)
       {
       answer+=abs(ans[i]-ans[i+1]);
       
       }
       
       cnt =0;
       
       for (int i=1;i<n;i=i+2)
       {
           
           ans[i]=a[cnt];
           cnt+=1;
          
       }
       
       for (int i=0;i<n;i=i+2)
       {
           ans[i]=a[cnt];
           cnt+=1;
           
       }
       
        for(int i=0;i<n-1;i++)
       {
       answer_temp+=abs(ans[i]-ans[i+1]);
       
       }
       
       answer=max(answer,answer_temp);
      
   }
   
   
             cout <<answer<<endl; 
   
   
   
   return 0;
}