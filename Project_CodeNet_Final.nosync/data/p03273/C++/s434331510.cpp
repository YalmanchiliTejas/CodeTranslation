#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c;
int h,w,i,j;
int a[105],b[105];
int s[105][105];
int main(){

 cin>>h>>w;
 for(int i=1;i<=h;i++)
   for(int j=1;j<=w;j++)
     
 {
   cin>>c;
   if(c=='.')s[i][j]=1;
   else s[i][j]=-1;     
 }
 for(int i=1;i<=h;i++)
 {
 	int t=0;
 	for(int j=1;j<=w;j++)
 	    t+=s[i][j];
 	if(t==w) a[i]=1;  
 }
  for(int i=1;i<=w;i++)
 {
 	int t=0;
 	for(int j=1;j<=h;j++)
 	    t+=s[j][i];
 	if(t==h) b[i]=1;  
 }  
  for(int i=1;i<=h;i++)
 {
 	if(a[i]==1)continue;
 	for(int j=1;j<=w;j++)
     
 {
     if(b[j]==1)continue; 
   if(s[i][j]==1)cout<<'.';
   else cout<<'#';     
 }
 cout<<endl;
   }  
   
	return 0;
}
