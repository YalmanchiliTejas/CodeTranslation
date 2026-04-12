#include<bits/stdc++.h>
#include<queue>

using namespace std;
int main(){
int N;
cin>>N;
  int h[N];
    for(int i = 0;i<N;i++){
cin>>h[i];
    }
  int ans = 1;
    for(int x = 1;x<N;x++){
      int cnt = 0;
      for(int y = 0;y<x;y++){
        if(h[y]<=h[x]){
          cnt++;
        }
      }
      if(cnt == x){
          ans++;
        }
    }
  cout<<ans;
}