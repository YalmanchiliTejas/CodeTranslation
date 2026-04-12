#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  deque<ll> q;
  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    auto itr = lower_bound(q.begin(), q.end(), tmp);
    int index = distance(q.begin(), itr);
    if(index == 0){
      q.push_front(tmp);
    } else { 
      q[index-1] = tmp;
    }
  }
  cout << q.size() << endl;
}
