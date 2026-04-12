#include <bits/stdc++.h>
using namespace std;

int main()
{
  string c,ans;
  cin>>c;
  string vowel = "aeiou";
  for(int i=0;i<vowel.size();i++)
  {
	if (vowel.at(i)==c.at(0))
    {
      ans="vowel";
      break;
    }
    else ans="consonant";
  }
  cout<<ans<<endl;
}