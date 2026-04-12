#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
const ll INF = 1000000000000007;

using namespace std;

int main(){
    ll N;
    cin >> N;
    vector <ll> X(N,0);
    vector <ll> moto_X(N,0);

    REP(i,N)
    {
      cin >> X[i];
    }
    //元の状態をとっておく
    moto_X = X;

    sort(X.begin(),X.end());

    //1番目を取り除いたもの 
    //値は中央値付近のN/2 or N/2 - 1どちらかになるはず、、、
    //moto_X[i] <= X[N/2 -1] なら X[N/2]が中央値

    REP(i,N)
    {
      if(moto_X[i] <= X[N/2 - 1])
      {
        cout << X[N/2] << endl;
      }
      else
      {
        cout << X[N/2 - 1] << endl;
      }
    }
    return 0;

}