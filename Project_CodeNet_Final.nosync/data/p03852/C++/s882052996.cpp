#include <bits/stdc++.h>
using namespace std;
int main () {
  char c;
  cin>>c;
  int x=0;
  if (c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
    x=1;
  }
  if (x==1){
    cout<<"vowel"<<endl;
  }
  else{
    cout<<"consonant"<<endl;
  }
}