#include<iostream>
#include<algorithm>

using namespace std;
int64_t Len[51], Pat[51];

int64_t rec(int64_t k, int64_t x){
  if(x == Len[k]) return Pat[k];
  int64_t ans = 0;

  x--; //下のバンズ
  if(x > 0){
    int64_t l = min(x, Len[k-1]);
    ans += rec(k-1, l);
    x -= l;
  }

  if(x > 0){ // 真ん中のパテ
    ans++;
    x--;
  }
  if(x > 0){
    int64_t l = min(x, Len[k-1]);
    ans += rec(k-1, l);
    x -= l;
  }
  return ans;
}

int main(){
  int64_t N, X;
  cin >> N >> X;

  Len[0] = Pat[0] = 1;
  for(int i = 1; i <= N; i++){
    Len[i] = Len[i-1] * 2 + 3;
    Pat[i] = Pat[i-1] * 2 + 1;
  }
  cout << rec(N, X) << endl;
  return 0;
}
