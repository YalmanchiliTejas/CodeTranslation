#include <bits/stdc++.h>

#define PI acos(-1)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define io  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen ("team.in", "r", stdin),freopen ("team.out", "w", stdout);
#define fileIn freopen ("in.txt", "r", stdin);
#define all(v) ((v).begin()), ((v).end())


using namespace std;

typedef pair<int, int> pii;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pli;



int main () {
  io;
  deque<int> dq;

  int n;
  cin >> n;
  bool f = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(f) {
      dq.push_back(x);
    }else {
      dq.push_front(x);
    }
    f ^= 1;
  }
  if(f) {
    while(dq.size()) {
      cout << dq.front() << " ";
      dq.pop_front();
    }
  }else {
    while(dq.size()) {
      cout << dq.back() << " ";
      dq.pop_back();
    }

  }
  cout << endl;
  return 0;
}



