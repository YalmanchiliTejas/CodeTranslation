#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {  
  return b != 0 ? gcd(b, a % b) : a;
}//MAX
int lcm(int a, int b) { 
   return a * b / gcd(a, b);
   }
//MIN

 main() {
string s;
cin >> s;
bool ans = false;
for(int i=1;i<s.size();i++){
    if(s.at(i-1)=='A'&&s.at(i)=='C')ans =true;
}
if(ans)cout<<"Yes"<<endl;
else cout <<"No"<<endl;
}
