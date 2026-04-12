#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef set<int> S;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

  string s;
  cin >> s;
  if((s[0]=='A' && s[1]=='A' && s[2]=='A') || (s[0]=='B' && s[1]=='B' && s[2]=='B')){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

	return 0;
}