#include <bits/stdc++.h>
using namespace std;
int main() {

int a,b[30],c;
   cin >> a;

for (int i = 0; i < a; ++i) 
cin >> b[i];

 c = 0;
for (int i = 0; i < a; ++i) {
bool abc = true;
for (int j = 0; j < i; ++j) {
if (b[j] > b[i]) {
 abc = false;
break;
}
}
if (abc) {
++c;
}
}

cout << c << endl;
}
