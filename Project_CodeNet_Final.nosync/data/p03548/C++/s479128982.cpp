#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
long int x,y,z;
int main(){
  cin >> x >> y >> z;
  cout << (x-z)/(y+z) << endl;
}
