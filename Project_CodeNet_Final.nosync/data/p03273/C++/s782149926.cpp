#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
  
      int h,w;
      cin>>h>>w;
      int i,j,k,cnt=0;
      char mat[h+1][w+1];
      
      for(i=0;i<h;++i)
         {
             for(j=0;j<w;++j)
               {
                   cin>>mat[i][j];
               }
         }
         
       for(i=0;i<h;++i)
         {  
             cnt=0;
             for(k=0;k<w;++k)
               {
                   if(mat[i][k]=='#')
                      cnt++;
                      
               }
               
              if(cnt==0)
                {
                    for(k=0;k<w;++k)
                       mat[i][k]='*';
                }
                
             
         }
         
         for(j=0;j<w;++j)
          {
              cnt=0;
               for(k=0;k<h;++k)
               {
                   if(mat[k][j]=='#')
                      cnt++;
                      
               }
               
              if(cnt==0)
                {
                    for(k=0;k<h;++k)
                       mat[k][j]='*';
                }
              
          }
          
          int flag;
          for(i=0;i<h;++i)
            { 
                 flag=0;
                for(j=0;j<w;++j)
                  {
                      if(mat[i][j]!='*')
                        { cout<<mat[i][j];
                          flag=1;
                        }
                  }
               if(flag==1)   
                  cout<<endl;
                  
                  
            }
    
    	return 0;
} 