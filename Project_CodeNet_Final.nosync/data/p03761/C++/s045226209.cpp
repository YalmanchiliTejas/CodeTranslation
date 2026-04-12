#include <bits/stdc++.h> 

#define INF INT_MAX/2
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin>>n;
   vector<string>s(n);
   for(int i=0;i<n;i++)cin>>s[i];
   vector<int>ans(26,INF);
   for(int i=0;i<26;i++){
      for(int j=0;j<n;j++){
         int c = 0;
         for(int k=0;k<s[j].size();k++){
            if(s[j][k] == (char)('a'+i))c++;
         }
         ans[i] = min(ans[i],max(c,0));
      }
   }
   //for(int i=0;i<n;i++)cout<<ans[i]<<" "<<((char)('a'+i))<<endl;
   for(int i=0;i<26;i++){
      for(int j=0;j<ans[i];j++){
         cout<<(char)('a'+i);
      }
   }
   cout<<endl;
   return 0; 
}
