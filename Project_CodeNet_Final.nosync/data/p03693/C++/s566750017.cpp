#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
   int r , g ,b;
   cin >> r >> g >> b;
   int total = r * 100 + g * 10 + b;
   if( total % 4 == 0){
       cout << "YES" << endl;
   }else{
       cout << "NO" << endl;
   }
}
