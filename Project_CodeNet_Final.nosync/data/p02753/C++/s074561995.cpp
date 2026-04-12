#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main()
{
  string S;
  cin >> S;
  cout << ((S == "AAA" || S == "BBB") ? "No" : "Yes") << endl;
  return 0;
}
