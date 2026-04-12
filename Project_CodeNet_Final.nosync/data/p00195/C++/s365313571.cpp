
#include<iostream>
#include<map>
using namespace std;

int main()
{
  map< int, char, greater<int> > m;
  int s1, s2;
  int i;
  while (cin>>s1>>s2, s1||s2) {
    m.clear();
    m[s1+s2] = 'A';
    for (i = 1; i < 5; i++) {
      cin>>s1>>s2;
      m[s1+s2] = 'A'+i;
    }
    cout<<(*m.begin()).second<<" "<<(*m.begin()).first<<endl;
  }
  return 0;
}