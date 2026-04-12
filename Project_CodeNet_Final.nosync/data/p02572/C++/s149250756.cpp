#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t total=0;
  int64_t a[200010];
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
  cin>>a[i];
  }
  int64_t b=0;
  for(int i=0;i<N;i++){
    total += b*a[i]%1000000007;
     b += a[i];
     b %= 1000000007;
  }
   cout<<total%1000000007<<endl;
}