#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define P pair<long long, long long>


using namespace std;
const long long int MOD=1e9+7;

int main(){
  string s;
  cin >> s;
  if(s[0]==s[1] && s[1]==s[2]){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}