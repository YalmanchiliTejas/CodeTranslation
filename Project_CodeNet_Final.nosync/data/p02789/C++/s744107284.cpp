#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> p;

int main(void){
  int N,M;
  cin >> N >> M;

  string ans;
  if(N != M){
    ans = "No";
  }else{
    ans = "Yes";
  }

  cout << ans << endl;
}
