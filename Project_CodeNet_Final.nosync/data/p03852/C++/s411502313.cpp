#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  char a;
  string ans="consonant";
    cin >> a;
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
      ans = "vowel";
    cout << ans << endl;
}