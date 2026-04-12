//
//  main.cpp
//  CoderWork
//
//  Created by Minoru Hayashi on 2020/02/29.
//  Copyright © 2020 Minoru Hayashi. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i=0; i<(n); i++)
#define REP2(i,x,n) for (int i=x; i<(n); i++)
#define ALL(n) begin(n), end(n)

using ll = long long;

template<class T> inline bool chmin(T& a, T b){ if(a>b){a=b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b){ if(a<b){a=b; return 1;} return 0;}

// const ll INF = 1LL<<60;
// const ll MOD = 1000000007;

//#define __DBG__


void solve(void){

  string S;
  
  cin >> S;
  
  
	if(S=="AAA" || S=="BBB"){
      cout << "No" << endl;
    }
  else
  {
    cout << "Yes" << endl;
  }

  return;
}

int main(int argc, const char * argv[]) {



    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    solve();
 
    return 0;
}

