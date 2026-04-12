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



void solve(void){

  int N, M;
  
  cin >> N >> M;
  
  if(M<N){
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
