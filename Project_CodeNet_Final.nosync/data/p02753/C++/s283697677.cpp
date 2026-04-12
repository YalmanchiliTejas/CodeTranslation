#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string str;
  cin >> str;
  
  int found=0;
  
  if(str[0]=='A'|| str[1]=='A' || str[2]=='A') found++;
  
  if(str[0]=='B' || str[1]=='B' || str[2]=='B') found++;
  
  if(found == 2) printf("Yes");
  else printf("No");
  
  return 0;
}