#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  scanf("%c",&c);
  printf("%s\n",(c=='a' || c=='i' || c=='u' || c=='e' || c=='o')
                ? "vowel" : "consonant");
}
