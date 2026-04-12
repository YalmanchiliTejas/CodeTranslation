#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string c;
  cin>>c;
  if(c[0]=='a' || c[0]=='e' ||c[0]=='i' || c[0]=='o' || c[0]=='u' ){
    cout<<"vowel"<<"\n";
  }
  else{
    cout<<"consonant"<<"\n";
  }
  
  return 0;
}