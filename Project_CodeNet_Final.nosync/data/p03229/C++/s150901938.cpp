#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX_N = (int)(1e5 + 5);

int n;
deque<ll> a;

deque<ll> ans_deq;

ll ans;

ll mysolve() {
  deque<ll> ans_deq;

  ans_deq.push_front(a.front());
  a.pop_front();

  while (!a.empty()) {

    if (abs(ans_deq.front() - a.front()) >= abs(ans_deq.back() - a.front()) &&
        abs(ans_deq.front() - a.front()) >= abs(ans_deq.back() - a.back()) &&
        abs(ans_deq.front() - a.front()) >= abs(ans_deq.front() - a.front()) &&
        abs(ans_deq.front() - a.front()) >= abs(ans_deq.front() - a.back())) {
      ans_deq.push_front(a.front());
      a.pop_front();
    }
    else if (abs(ans_deq.front() - a.back()) >= abs(ans_deq.back() - a.front()) &&
             abs(ans_deq.front() - a.back()) >= abs(ans_deq.back() - a.back()) &&
             abs(ans_deq.front() - a.back()) >= abs(ans_deq.front() - a.front()) &&
             abs(ans_deq.front() - a.back()) >= abs(ans_deq.front() - a.back())) {
      ans_deq.push_front(a.back());
      a.pop_back();
    }
    else if (abs(ans_deq.back() - a.front()) >= abs(ans_deq.back() - a.front()) &&
             abs(ans_deq.back() - a.front()) >= abs(ans_deq.back() - a.back()) &&
             abs(ans_deq.back() - a.front()) >= abs(ans_deq.front() - a.front()) &&
             abs(ans_deq.back() - a.front()) >= abs(ans_deq.front() - a.back())) {
      ans_deq.push_back(a.front());
      a.pop_front();
    }
    else if (abs(ans_deq.back() - a.back()) >= abs(ans_deq.back() - a.front()) &&
             abs(ans_deq.back() - a.back()) >= abs(ans_deq.back() - a.back()) &&
             abs(ans_deq.back() - a.back()) >= abs(ans_deq.front() - a.front()) &&
             abs(ans_deq.back() - a.back()) >= abs(ans_deq.front() - a.back())) {
      ans_deq.push_back(a.back());
      a.pop_back();
    }

    /*
    for (auto e: ans_deq) {
      printf("%lld ", e);
    }
    printf("\n");
    */
  }

  ll tmpans = 0;

  for (int i = 1; i < ans_deq.size(); ++i) {
    tmpans += abs(ans_deq[i] - ans_deq[i - 1]);
  }

  return tmpans;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    ll tmp;
    scanf("%lld", &tmp);
    a.push_front(tmp);
  }


  sort(a.begin(), a.end());

  ll my = mysolve();

  printf("%lld\n", my);
}