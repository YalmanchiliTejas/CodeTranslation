#include <iostream>
#include <vector>
#include <map>

using namespace	std;

int main(){
  int n;
  string s;
  map <char, int> ch_count, ch_count_tmp;
  cin >> n;
  for (int i=0;i<n;i++)	{
    cin >>s;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
      ch_count_tmp[letter] = 0;
    }
    for	(string::iterator it=s.begin();it!=s.end();it++) {
      ch_count_tmp[*it]++;
    }
    for (char letter = 'a'; letter <= 'z'; ++letter) {
      if (ch_count.find(letter) == ch_count.end() || ch_count[letter] > ch_count_tmp[letter]) {
        ch_count[letter] = ch_count_tmp[letter];
      }

    }
  }

  for (char letter = 'a'; letter <= 'z'; ++letter) {
    if (ch_count[letter] > 0) {
      string res = string(ch_count[letter], letter);
      cout << res;
    }
  }
  cout << endl;
}

