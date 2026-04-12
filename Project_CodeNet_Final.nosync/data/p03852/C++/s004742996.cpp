#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

char c;

int main(int argc, const char * argv[]) {
  cin >> c;
  
  if (c == 'a' || c == 'i'|| c == 'u'|| c == 'e'|| c == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  return 0;
}
