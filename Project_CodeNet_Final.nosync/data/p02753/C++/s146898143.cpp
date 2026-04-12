#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>

using namespace std;


int main()
{
  string S;
  cin >> S;
  if(S[0] == S[1] && S[0] == S[2]){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }

  return 0;
}
