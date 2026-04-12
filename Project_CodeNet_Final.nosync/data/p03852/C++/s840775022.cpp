#include<iostream>
using namespace std;

int main()
{
  char c;
  cin>>c;
  
  if(('a' == c)||
     ('e' == c)||
     ('i' == c)||
     ('o' == c)||
     ('u' == c))
  {
    cout<<"vowel"<<endl;
  }
  else
  {
    cout<<"consonant"<<endl;
  }
  
  return 0;
}

    