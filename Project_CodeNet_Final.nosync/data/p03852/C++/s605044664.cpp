#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int main(){
  typedef long long int ll;
string A, B, C,D;
cin >> A;
bool ans = false;
if(A[0] == 'a' || A[0] == 'i' || A[0] == 'u' || A[0] == 'e' || A[0] == 'o')ans = true;
if(ans)cout << "vowel" << endl;
else cout << "consonant" << endl;
        return 0;
}