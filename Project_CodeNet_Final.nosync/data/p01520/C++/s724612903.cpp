#include<iostream>
#include<algorithm>
#define INF 1<<30
using namespace std;

int main(){
  
  int N,T,E;
  int a;
  int ans=-1;
  cin >> N >> T >>E;

  for(int i=0;i<N;i++){
    cin >> a;
    for(int j=0;j<=T+E;j++){
      if( T-E<=a*j && a*j<= T+E)ans = i+1;
    }
  }

  cout << ans << endl;

  return 0;
}