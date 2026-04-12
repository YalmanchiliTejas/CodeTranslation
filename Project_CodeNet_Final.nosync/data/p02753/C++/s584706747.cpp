#include <bits/stdc++.h>
using namespace std;
 
int main() {
	char a,b,c;
  cin >> a >> b >> c;
  string answer = "Yes";
  if((a==b) && (b==c))
     answer = "No";
     cout << answer << endl;
}