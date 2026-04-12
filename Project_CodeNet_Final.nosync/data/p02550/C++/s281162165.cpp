#include <vector>
#include <iostream>
#include <map>
using namespace std;
using ll = int64_t;

int main() {
  ll n,x,m;
  cin >> n >> x >> m;
  map<ll,ll> AM;
  vector<ll> A;
  ll sum = 0;
  bool found_cycle = false;
  while(n>0) {
    A.push_back(x);
    sum += x;
    n--;
    if(!found_cycle) {
      if(AM.count(x) == 1) {
        ll cycle_length = A.size()-AM[x];
        ll cycle_sum = 0;
        for(ll i=A.size()-cycle_length; i<A.size(); i++) {
          cycle_sum += A[i];
        }
        //cerr << "CYCLE: A[" << A.size() << "] = A[" << AM[x] << "] = " << x << " length=" << cycle_length << " sum=" << cycle_sum << endl;

        ll amt = n/cycle_length;
        sum += amt*cycle_sum;
        n -= amt*cycle_length;
        found_cycle = true;
      } else {
        AM[x] = A.size();
      }
    }
    x = (x*x)%m;
  }
  cout << sum << endl;
}
