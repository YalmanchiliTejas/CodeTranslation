#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(int argc, char *argv[])
{
  string exp;
  cin >> exp;
  int ans;
  cin >> ans;
  auto parseLR = [](const string &e) {
    int c = e[0] - '0';
    for(int i = 1; i < e.size(); i++) {
      if(e[i] == '*') {
        c *= e[i+1] - '0';
        i++;
      } else if(e[i] == '+') {
        c += e[i+1] - '0';
        i++;
      } else {
        throw string("something wrong!");
      }
    }
    return c;
  };
  auto num = [](const string &e, int &i) {
    return e[i++] - '0';
  };
  auto mul = [&num](const string &e, int &i) {
    int c = num(e,i);
    while(i < e.size() && e[i] == '*') {
      i++;
      c *= num(e,i);
    }
    return c;
  };
  auto add = [&mul](const string &e, int &i) {
    int c = mul(e,i);
    while(i < e.size() && e[i] == '+') {
      i++;
      c += mul(e,i);
    }
    return c;
  };
  auto parse = [&add](const string &e) {
    int i = 0;
    return add(e, i);
  };
  bool lr = parseLR(exp) == ans;
  bool ty = parse(exp) == ans;
  if(lr && ty) {
    cout << "U" << endl;;
  } else if(lr) {
    cout << "L" << endl;
  } else if(ty) {
    cout << "M" << endl;
  } else {
    cout << "I" << endl;
  }
  return 0;
}

