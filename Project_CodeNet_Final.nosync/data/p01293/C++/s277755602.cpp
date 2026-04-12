#include <bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, char>;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  char tr;
  while ( cin >> tr, tr != '#' ) {
    P cards[4][13];
    for ( int i = 0; i < 4; i++ ) {
      for ( int j = 0; j < 13; j++ ) {
	string s;
	cin >> s;
	if ( isdigit(s[0]) ) cards[i][j] = {s[0]-'0', s[1]};	  
	else if ( s[0] == 'T' ) cards[i][j] = {10, s[1]};	  
	else if ( s[0] == 'J' ) cards[i][j] = {11, s[1]};	  
	else if ( s[0] == 'Q' ) cards[i][j] = {12, s[1]};	  
	else if ( s[0] == 'K' ) cards[i][j] = {13, s[1]};	  
	else cards[i][j] = {14, s[1]};	        
      }
    }

    int score[2] = {};
    int ldr = 0;    
    for ( int t = 0; t < 13; t++ ) {
      int win = ldr;
      int num = cards[ldr][t].first;      
      char suit = cards[ldr][t].second;      
      for ( int i = 1; i < 4; i++ ) {
	int mem = (ldr+i)%4;	
	int num_ = cards[mem][t].first;
	int suit_ = cards[mem][t].second;
	if ( suit_ == tr ) {
	  if ( suit != suit_ ) num = -1;	  
	  if ( num < num_ ) {
	    num = num_;
	    suit = suit_;
	    win = mem;	    
	  }
	} else if ( suit == suit_ ) {
	  if ( num < num_ ) {
	    num = num_;
	    win = mem;	    
	  }
	}
      }
      ldr = win;      
      score[win%2]++;    
    }

    if ( score[0] > 6 ) cout << "NS " << score[0]-6 << endl;
    else cout << "EW " << score[1]-6 << endl; 
  }
  
  return 0;
}

