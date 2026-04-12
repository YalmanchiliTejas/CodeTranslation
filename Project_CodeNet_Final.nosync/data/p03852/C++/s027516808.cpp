#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  bool isVowel=false;
  char c;
  cin>>c;
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
    isVowel=true;
  }
  
  if(isVowel){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }
  return 0;
}
