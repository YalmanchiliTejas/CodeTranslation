#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  vector<bool> fg(N, false);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);
  sort( A.begin(), A.end() );
  
  deque<int> d;
  d.push_back(A.at(0));
  fg.at(0) = true;
  
  for( int i = 1; i < N; i+= 2 ){
    if( N-i > 0 && fg.at(N-i) == false ){
      fg.at(N-i) = true;
      d.push_front(A.at(N-i));
    }
    if( N-i-1 > 0 && fg.at(N-i-1) == false ){
      fg.at(N-i-1) = true;
      d.push_back(A.at(N-i-1));
    }
    if( fg.at(i) == false ){
      fg.at(i) = true;
      d.push_front(A.at(i));
    }
    if( i+1 < N && fg.at(i+1) == false ){
      fg.at(i+1) = true;
      d.push_back(A.at(i+1));
    }
  }
  
  reverse( A.begin(), A.end() );
  deque<int> d2;
  vector<bool> fg2(N, false);
  d2.push_back(A.at(0));
  fg2.at(0) = true;
  
  for( int i = 1; i < N; i+= 2 ){
    if( N-i > 0 && fg2.at(N-i) == false ){
      fg2.at(N-i) = true;
      d2.push_front(A.at(N-i));
    }
    if( N-i-1 > 0 && fg2.at(N-i-1) == false ){
      fg2.at(N-i-1) = true;
      d2.push_back(A.at(N-i-1));
    }
    if( fg2.at(i) == false ){
      fg2.at(i) = true;
      d2.push_front(A.at(i));
    }
    if( i+1 < N && fg2.at(i+1) == false ){
      fg2.at(i+1) = true;
      d2.push_back(A.at(i+1));
    }
  }

  
  
  
 
  int ans = 0;
  int ans2 = 0;
  for( int i = 1; i < N; i++ ){
    ans += abs( d.at(i) - d.at(i-1) );
    ans2 += abs( d2.at(i) - d2.at(i-1) );
  }
  cout << max(ans, ans2) << endl;
    
    
}