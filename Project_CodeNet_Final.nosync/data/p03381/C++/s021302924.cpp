#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <ctime>
#include <random>
#include <chrono>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;
const ll INF = 100100100100100100;

ll N;
ll x[200200];
ll xx[200200];
int main(){
  cin >> N;
  rep(i,N){
    cin >> x[i];
    xx[i] = x[i];
  }
  sort(x,x+N);
  ll a = x[N/2 -1];
  ll b = x[N/2];
  rep(i,N){
    if(xx[i] <= a){
      cout << b << endl;
    }
    else{
      cout << a << endl;
    }
  }
}
