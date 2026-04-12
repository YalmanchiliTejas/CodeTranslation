#include<bits/stdc++.h>
using namespace std;
int main(){
 string s[50];
 int n;
 cin>>n;
 cin>>s[0];
 int a=0,b=s[0].size();

 for(int i=1;i<n;i++){
  cin>>s[i];
  if(b>s[i].size())a=i;
 }

 int vc[26]={};
 for(int i=0;i<s[a].size();i++)vc[(int)(s[a][i])-97]++;

 for(int i=0;i<26;i++)
  if(vc[i]!=0){
   char ch=(char)(i+97);
   int min=vc[i];
   for(int k=1;k<n;k++){
    int count=0;
    for(int j=0;j<s[k].size();j++)
     if(s[k][j]==ch)count++;
    if(min>count)min=count;
   }
   vc[i]=min;
  }

 for(int i=0;i<26;i++)
  if(vc[i]!=0)
   for(int j=0;j<vc[i];j++)cout<<(char)(i+97);
 cout<<endl;
 return 0;
}