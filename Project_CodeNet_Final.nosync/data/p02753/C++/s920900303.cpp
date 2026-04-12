#include <iostream>
using namespace std;
 
 
int main() {
  string S;
  cin >> S;
  

string result;
if ((S[0]!=S[1])|(S[0]!=S[2])|(S[1]!=S[2]))
  result = "Yes";
else
  result = "No";


cout << result << endl;
}
 