#include <bits/stdc++.h>
using namespace std;
int sum=0;
int A=0;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

 // 椅子の幅 Xcm, 一人あたりの使用幅 Ycm、間隔 Zcm
 // A人座った場合、に必要な幅
 // Z + Y + Z + Y + Z + Y + Z
 // (Z+Y)*A + Z
 while (sum <= X){
   A++;
   sum = (Z+Y)*A+Z;
 }

 A--;

    cout << A << endl;
}
