#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {

  char a[4];
  for(int i=0;i<3;i++)cin >> a[i];
  if(a[0]==a[1]&&a[1]==a[2])cout << "No" << endl;
  else cout << "Yes" << endl;

}
