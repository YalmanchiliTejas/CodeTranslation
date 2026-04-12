#include <bits/stdc++.h>

using namespace std;
int main()
{
 
   string s;
  cin>>s;
  int i;
  int c1=0,c2=0;
  for(i=0;s[i];++i)
  {
     if(s[i]=='A')
         c1++;
    
      else 
        c2++;
  }
  if(c1>0 && c2>0)
       printf("Yes");
  
  else
     printf("No");  

}
   