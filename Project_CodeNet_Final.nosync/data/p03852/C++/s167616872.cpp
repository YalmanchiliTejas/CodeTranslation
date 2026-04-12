#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
inline int isVowel(const char c){
  if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
    return 1;
  }
  if(c=='A'||c=='I'||c=='U'||c=='E'||c=='O'){
    return 1;
  }
  return 0;
}
int main(){
  char C;
  rd(C);
  if(isVowel(C)){
    wt_L("vowel");
    wt_L('\n');
  }
  else{
    wt_L("consonant");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190822-2

// --- original code ---
// {
//   char C;
//   rd(C);
//   wt( if[isVowel(C), "vowel", "consonant"] );
// }
