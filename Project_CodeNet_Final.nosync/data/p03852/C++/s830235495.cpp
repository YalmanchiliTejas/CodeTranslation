#include <iostream>
//#include <string>
using namespace std;

int main(){
  char s;
  cin>>s;
  //for (int i=0;i<s.size();i++){
    //if (s.at(i)!='a'&&s.at(i)!='e'&&s.at(i)!='i'&&s.at(i)!='o'&&s.at(i)!='u'){

      //return 0;
    //}
  //}
  if (s!='a'&&s!='e'&&s!='i'&&s!='o'&&s!='u'){
    cout<<"consonant"<<endl;
  }
  else{
    cout<<"vowel"<<endl;
  }

  return 0;
}
