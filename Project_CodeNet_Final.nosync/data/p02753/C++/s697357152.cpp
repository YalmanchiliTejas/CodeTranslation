#include <stack>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <iomanip>
using namespace std;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
int main(){
    //std::stack<int> stack;
    string s;
    cin >> s;
    string ans = "Yes";
    if(s == "AAA" || s == "BBB"){
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}



