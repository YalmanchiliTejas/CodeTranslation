#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
  int N,K;
  char S[10];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> S[i];
  }
  cin >> K;
  for(int i=0;i<N;i++){
    if(S[K-1] != S[i]){
      S[i] = '*';
    }
  }
  for(int i=0;i<N;i++){
  cout << S[i];
  }
}
