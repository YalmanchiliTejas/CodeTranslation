#include <iostream>
using namespace std;

string tmp = "qwertasdfgzxcvb";

int main()
{
  string str;

  while (cin >> str, str[0] != '#'){
    int ct = 0;
    for (int i = 1; i < str.size(); i++){
      bool jg1, jg2;
      jg1 = jg2 = false;
      for (int j = 0; j < tmp.size(); j++){
        if (str[i] == tmp[j]) jg1 = true;
        if (str[i - 1] == tmp[j]) jg2 = true;
      }
      ct += (jg1 ^ jg2);
    }
    cout << ct << endl;
  }
  return (0);
}