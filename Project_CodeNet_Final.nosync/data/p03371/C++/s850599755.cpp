#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)


int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  if(A + B < C*2) {
    //not using C
    cout << A*X + B*Y << endl;;
    return 0 ; 
  }

  ll res = 0;
  if ( X > Y ) {
    res = C*2*Y;
    X -= Y;
    res += min(C*2*X, A*X);
  } else {
    res = C*2*X;
    Y -= X;
    res += min(C*2*Y, B*Y);
  }

  cout << res << endl;

    
  




}
