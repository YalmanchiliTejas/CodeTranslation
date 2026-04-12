#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  int ans=0;

  cin >> s;

  for(int i=0;i<6;i++)if(s[i]=='A'&&s[i+1]=='C')ans = 1;

  if(ans==1)cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
