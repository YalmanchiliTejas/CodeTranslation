/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Jan 02 22:33:27 2019
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;


int a[55][26];
int main(){
#ifndef ONLINE_JUDGE
   //freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
   int n;
   cin>>n;
   string s;
   for(int i=0;i<n;i++){
        cin>>s;
        for(char c:s){
        	a[i][c-'a']++;
        }
   }
   string ans="";
   for(int i=0;i<26;i++){
         int m=1e9;
   	 for(int j=0;j<n;j++){
   	        m=min(m,a[j][i]);
   	 }

   	 ans+=string(m,(char)(i+'a'));
   }
   cout<<ans<<endl;
   



}