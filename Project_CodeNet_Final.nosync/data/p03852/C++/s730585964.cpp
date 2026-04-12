#include<iostream>
using namespace std;
int main()
{
  char letter;
  cin>>letter;
  if(letter=='a'||letter=='i'||letter=='u'||letter=='e'||letter=='o'){
    cout<<"vowel"<<endl;
  }
  else{
    cout<<"consonant"<<endl;
  }
}