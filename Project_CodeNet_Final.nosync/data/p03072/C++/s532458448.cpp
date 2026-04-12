#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
typedef long long ll;

int main(void){
  int i,N;
  cin >> N;
  int x,max=0,count=0;
  REP(i,N){
    cin >> x;
    if(max<=x){
      max = x;
      count++;
    }
  }
  cout << count << endl; 
  return 0;
}
