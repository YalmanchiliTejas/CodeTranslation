#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s;
 int c2=0,c=0,i;
   cin>>s;
   for(i=0;i<3;i++)
   {
   	if(s[i]=='A')
   	{
   		c++;
   	}else if(s[i]=='B')
   	{
   		c2++;

   	}
   }
   if(c!=0&&c2!=0)
   {
   	cout<<"Yes"<<endl;
   }else
   {
   	cout<<"No"<<endl;
   }
   return 0;
}