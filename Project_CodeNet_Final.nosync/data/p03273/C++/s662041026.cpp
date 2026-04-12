#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
char a[104][104];
vector<int> del_hang;
vector<int> del_lie;
int main()
{
    int H,W;
    int i,j,k;
    int h,w;
    int flag;
    while(cin>>H>>W)
   {   
       memset(a,0,sizeof(a));
       del_hang.clear();
       del_lie.clear();
       for(i=0;i<H;i++)
          for(j=0;j<W;j++)
            cin>>a[i][j];
       for(j=0;j<H;j++)
       {
	 for(i=0;i<W;i++)
         {
          if(a[j][i]!='.') break;
         }
          if(i>=W) del_hang.push_back(j+1);
       }

       for(i=0;i<W;i++)
       {
	       for(j=0;j<H;j++)
         {
          if(a[j][i]!='.') break;
         }
          if(j>=H) del_lie.push_back(i+1);
       }
       
       for(i=0;i<W;i++) //列
       {
       	 vector<int>::iterator result = find( del_lie.begin( ), del_lie.end( ), i+1 ); 
         if(result==del_lie.end()) continue;
				  for(j=0;j<H;j++)//行
         {
           a[j][i]='@';
          }
       }

       for(i=0;i<H;i++) 
       {
          flag=0;
          for(j=0;j<W;j++)
         {
           if(del_hang.size())
           {
            if(i==del_hang[0]-1){del_hang.erase(del_hang.begin());break;}
            }
           if(a[i][j]!='@') 
            {cout<<a[i][j];flag=1;}
          }
          if(flag) cout<<endl;
       }
    }   

}