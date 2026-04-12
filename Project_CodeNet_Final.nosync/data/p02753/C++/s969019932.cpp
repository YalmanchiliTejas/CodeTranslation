#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

//#define DEBUG


int main(void)
{
  string S;
  cin >> S;
  if( S[0]==S[1] && S[1]==S[2])
  {
    cout << "No";
  }
  else
  {
    cout << "Yes";
  }
  
  return 0;
} 