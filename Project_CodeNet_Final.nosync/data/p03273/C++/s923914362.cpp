#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c;
int h,w,i,j;
int a[105],b[105];
char s[105][105];
int main(){

 cin>>h>>w;
 for(int i=1;i<=h;i++)
   for(int j=1;j<=w;j++)
     
 {
   cin>>s[i][j];
   if(s[i][j]=='#')a[i]=1,b[j]=1;
 }

  
  for(int i=1;i<=h;i++)
 {
 	if(a[i]==1)
 {  for(int j=1;j<=w;j++)
 		
     
 {
  if(b[j]==1) cout<<s[i][j]; 
   
 }
 cout<<endl;
   }  
   }
	return 0;
}
