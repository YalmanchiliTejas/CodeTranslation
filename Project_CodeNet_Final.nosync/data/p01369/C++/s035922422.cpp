#include <iostream>
using namespace std;
#define rep2(i, n) for(int i = 0 ; i < n ; i++)
#define rep(i, moji_len) for(int i = 0 ; i < moji_len ; i++)
#define n 33

int main()
{
  char moji[33];
  while(true){
    cin >> moji;
    if(moji[0] == '#') break;
    int moji_len = 0, cnt = 0;
    
    rep(i, n){
      if(moji[i] == '\0'){
	moji_len = i;
	break;
      }
    }
    int hand = -1;
    rep(i, moji_len){
      if(moji[i] == 'y' || moji[i] == 'u' || moji[i] == 'o' || moji[i] == 'p' || moji[i] == 'i' || moji[i] == 'h' || moji[i] == 'j' || moji[i] == 'k' || moji[i] == 'l' || moji[i] == 'n' || moji[i] == 'm'){
	if(hand == -1){
	  hand = 0;
	}
	if(hand == 1){
	  hand = 0;
	  cnt++;
	}
      }else if(moji[i] == 'q' || moji[i] == 'w' || moji[i] == 'e' || moji[i] == 'r' || moji[i] == 't' || moji[i] == 'a' || moji[i] == 's' || moji[i] == 'd' || moji[i] == 'f' || moji[i] == 'g' || moji[i] == 'z' || moji[i] == 'x' || moji[i] == 'c' || moji[i] == 'v' || moji[i] == 'b'){
	if(hand == -1){
	  hand = 1;
	}
	if(hand == 0){
	    hand = 1;
	    cnt++;
	}
      }
    }
    cout << cnt << '\n'; 
  }
}