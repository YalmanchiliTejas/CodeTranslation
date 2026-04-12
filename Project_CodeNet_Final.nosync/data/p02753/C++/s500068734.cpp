#include <bits/stdc++.h>
using namespace std;

int main() {
string szo;
cin >> szo;
if (szo[0] == 'A') {
  if (szo[1] == 'A') {
 if (szo[2] == 'A') {
  cout << "No";
} else {
  cout << "Yes";
}
 } else {
 if (szo[2] == 'B') {
  cout << "Yes";
} else {
  if (szo[2] == 'A'){
      cout << "Yes";
  }
}
 }
} else {
  if (szo[1] == 'B') {
 if (szo[2] == 'B') {
  cout << "No";
} else {
  cout << "Yes";
}
  } else {
     if (szo[2] == 'B') {
  cout << "Yes";
} else {
  if (szo[2] == 'A') {
        cout << "Yes";
  }
}
}
}
	return 0;
}
