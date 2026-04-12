#include<bits/stdc++.h>
using namespace std;
int main()
{
  string  S, ans;
  cin >> S;
  ans = "Yes";
  if(S == "AAA" || S == "BBB"){
    ans = "No";
  }
  
  cout << ans <<endl;
}
