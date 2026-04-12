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

int main(){
  int N;
  int K;
  string S;

  cin >> N >> S >> K;

  char dame = S[K-1];
  for(int i=0;i<N;i++){
    if(S[i]!=dame){
      S[i] = '*';
    }
  }

  cout << S << endl;
  return 0;
}
