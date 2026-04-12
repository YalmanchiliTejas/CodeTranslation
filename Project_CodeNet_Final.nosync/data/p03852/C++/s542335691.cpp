  #include <iostream>
  using namespace std;
  int main(){
    string s;
    cin>>s;
    bool ans=false;
    if(s=="a"||s=="i"||s=="u"||s=="e"||s=="o")ans=true;
    cout<<(ans?"vowel":"consonant");
    return 0;
  }
  
