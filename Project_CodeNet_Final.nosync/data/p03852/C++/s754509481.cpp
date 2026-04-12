#include<iostream>

using namespace std;

int main(void)
{
  char s;
  cin>>s;
  
  if((s=='a')||(s=='e')){cout<<"vowel"<<endl; return 0;}
  if((s=='i')||(s=='o')){cout<<"vowel"<<endl; return 0;}
  if(s=='u'){cout<<"vowel"<<endl; return 0;}
  
  cout<<"consonant"<<endl;
  
  return 0;
}