#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<string> S(N);
   for(int i=0;i<N;i++){
      cin>>S[i];
   }
   vector<vector<int>> cnt(26,vector<int>(N));
   for(int i=0;i<N;i++){
      for(int j=0;j<S[i].size();j++){
         cnt[S[i][j]-'a'][i]++;
      }
   }
   int ans[26];
   for(int i=0;i<26;i++){
      ans[i]=10000;
   }
   for(int i=0;i<26;i++){
      for(int j=0;j<N;j++){
         ans[i]=min(ans[i],cnt[i][j]);
      }
   }
   for(int i=0;i<26;i++){
      for(int j=0;j<ans[i];j++){
         char s='a'+i;
         cout<<s;
      }
   }
   return 0;
}