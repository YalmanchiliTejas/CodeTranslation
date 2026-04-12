#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    // Your code here!
   int n;
   cin >> n;
   int cnt = n / 15;
   cout << n* 800 - cnt * 200 << endl;
}
