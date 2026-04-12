#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;
int main(){
  int N;
  cin >> N;

  vector<int> alphabets(26,50);
  string all = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0;i < N;i++){
    string s;
    cin >> s;

    map<char,int> mp;

    for(int j = 0;j < s.size();j++)mp[s[j]]++;

    for(int j = 0;j < 26;j++)alphabets[j] = min(alphabets[j],mp[all[j]]);
  }

  string ans = "";

  for(int i = 0;i < 26;i++)
    for(int j = 0;j < alphabets[i];j++)ans += all[i];

  cout << ans << endl;

}
