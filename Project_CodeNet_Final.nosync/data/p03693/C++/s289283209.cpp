#include <bits/stdc++.h>
using namespace std;


int main() {
int r,g,b;
cin >> r >> g >> b;

int A;
A = r*100 + g*10 + b;

if (A %4 == 0)  cout << "YES" << endl;
else  cout << "NO"  << endl;




return 0;
}
 