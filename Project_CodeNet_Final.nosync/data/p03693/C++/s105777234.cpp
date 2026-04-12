#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int main(){
  typedef long long int ll;
int A, B, C;
cin >> A >> B >> C;
bool ans = false;
if((A * 100 + B * 10 + C) % 4 == 0)ans = true;
if(ans)cout << "YES" << endl;
else cout << "NO" << endl;
        return 0;
}