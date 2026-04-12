#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >>b;
  double c=0;
  c+=1.0/(double)a;
  c+=1.0/(double)b;
  c=1.0/c;
  printf("%.10f\n",c);
}
