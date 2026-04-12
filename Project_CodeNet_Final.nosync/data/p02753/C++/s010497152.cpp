#include <bits/stdc++.h>
using namespace std;
int main(){
  bool boo = true;
  char c=getchar();
  for(int i=1;i<=2;++i){
    boo= (boo && (getchar()==c));
  }
  cout << (boo?"No":"Yes");
}