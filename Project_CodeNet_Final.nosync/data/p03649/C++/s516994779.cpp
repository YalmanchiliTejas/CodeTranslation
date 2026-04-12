#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cur = 0;

struct node{
  ll x, y;
  bool operator < (node other)const{
    return x + (cur - y) < other.x + (cur - other.y);

  }
};

int main(){

  ll n;

  cin >> n;

  ll x;

  priority_queue<node>pq;

  for(int i = 0; i < n; i++){


    cin >> x;
    pq.push(node{x, 0});



  }


  while(pq.top().x + (cur - pq.top().y) >= n){

    ll x = pq.top().x + (cur - pq.top().y);
    pq.pop();

    ll lo = 0, hi = 1e17;

    while(lo < hi){

      ll md = lo + (hi - lo)/2;

      if(x - (n * md) < n)hi = md;
      else
        lo = md + 1;
    }
    cur += lo;
    x -= (n * lo);
    pq.push(node{x, cur});

  }

  printf("%lld\n", cur);



}
