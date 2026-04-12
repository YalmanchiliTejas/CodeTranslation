#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<functional>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

int ans;

int main(){
  int N;
  cin >> N;
  int miria[20];
  int m;
  for(int i=0;i<N;i++){
    cin >> miria[i];
    if(i==0){
      m = miria[0];
      ans++;
    }
    if(i>=1){
      if(miria[i]>=m){
        ans++;
        m = miria[i];
      }
    }

  }
  cout << ans << endl;
  return 0;
}
