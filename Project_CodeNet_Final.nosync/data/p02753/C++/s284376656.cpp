#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
 int a=0,b=0;
 string s;
 cin >> s;
 rep(i,3){
   if (s[i]=='A') a++;
   else b++;
 }
 if ( a > 0 && b > 0) cout << "Yes" <<endl;
 else cout << "No" << endl;
 return 0; 
}
