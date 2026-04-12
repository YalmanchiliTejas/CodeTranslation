#include <bits/stdc++.h> 

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll ans = 0;

void p(int N,ll X){
   //cout<<N<<" "<<X<<" "<<ans<<endl;
   //全部
   if(X == pow(2,N+2)-3){
      ans += pow(2,N+1)-1;
      return ;
   }
   //何も食べない
   if(X == 0){
      return;
   }
   //真ん中のパティを食べる
   if(X > pow(2,N+1)-2){
      ans += pow(2,N);
      p(N-1,X-(pow(2,N+1)-1));
   }
   else{
      p(N-1,X-1);
   }
   return ;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

   int N;
   ll X;
   cin>>N>>X;
   p(N,X);
   cout<<ans<<endl;
   return 0;
}
