#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LIMIT 1000000007 //10^9+7
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

int main(){
	int N;cin>>N;
  int maxH = 0;
  int cnt = 0;
  rep(i,N){
    int h;cin>>h;
    if(h >= maxH){
      cnt++;
      maxH = h;
    }
  }
  cout<<cnt<<endl;
}