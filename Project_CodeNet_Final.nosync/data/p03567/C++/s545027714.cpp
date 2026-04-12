#include <iostream>
#include <string>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
  string S;
  cin >> S;

  rep(i, S.length()){
    if (S[i] == 'A'){
      if (S[i+1] == 'C'){
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
}