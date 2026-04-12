#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int a,b,c;
  cin>>a>>b>>c;
  int n=100*a+10*b+c;
  cout<<((n%4==0)?"YES":"NO")<<endl;
  return 0;
}
