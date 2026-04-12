#include<cstdio>
#include<bits/stdc++.h>
typedef long long int ll;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR_IN(i, a, b) for(int i = (a); i < (b); i++)
#define BETWEEN(x, a, b) ((x) >= (a) && (x) <= (b))
#define LOG_F 1
#define LOG(...) if(LOG_F) fprintf(stderr, __VA_ARGS__)

using namespace std;

/*
boin vowel
other consonant
 */
char c;

int main(){
  cin >> c;
  char vowel[] = "aiueo";
  bool f = false;
  REP(i,5){
    if(vowel[i]==c)
      f = true;
  }

  if(f)
    cout << "vowel\n";
  else
    cout << "consonant\n";

  return 0;
}
