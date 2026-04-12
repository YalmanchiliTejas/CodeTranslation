#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(void){
   
   int n;
   string s[55];
   vector<char> ss;
   cin>>n;
   int ans=2374823;
   for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<26;i++){
       char c='a';
       c+=i;
       for(int j=0;j<n;j++){
           int count=0;
           for(int k=0;k<s[j].size();k++){
               if(s[j][k]==c)count++;
           }
           ans=min(ans,count);
       }
       for(int j=0;j<ans;j++)ss.push_back(c);
       ans=2374823;
   }
   for(auto x:ss)cout<<x;
   
   
}
