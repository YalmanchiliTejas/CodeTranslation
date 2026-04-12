#include <bits/stdc++.h>
#include <ctype.h>
#include <math.h>
using namespace std;

int N;
int H[30];

int main(){
   cin>>N;
   for(int i=0;i<N;i++)cin>>H[i];
   int ans=0,s=H[0];
   for(int i=1;i<N;i++){
       s=max(s,H[i]);
       if(H[i]>=s)ans++;
   }
   cout<<ans+1<<endl;
}
