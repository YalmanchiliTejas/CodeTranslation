#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  int counter = 0;
  int highest;
  for(int i = 0; i < N; i++){
    if(i == 0 || H.at(i) >= highest){
      counter++;
      highest = H.at(i);
    }
  }
  cout << counter << endl;
}