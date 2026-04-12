#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char a;
  cin>>a;
  if(a=='a'||a=='i'||a=='u'||a=='e'||a=='o'){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }
  return 0;
}
