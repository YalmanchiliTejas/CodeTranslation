#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s;
  cin>>s;
  if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')
  {
      cout<<"vowel"<<endl;
  }
  else
  {
      cout<<"consonant"<<endl;
  }
   return 0;
}
