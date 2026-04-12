#include <iostream>

using namespace std;

void logic(char& status, const char op)
{
  if (status == '\0') {
    status = op;
  } else if (status == 'T' && op == 'F') {
    status = 'F';
  } else {
    status = 'T';
  }
}

int main()
{
  int n;
  char p;
  char status = '\0';

  cin >> n;
  while (n--) {
    cin >> p;
    logic(status, p);
  }

  cout << status << endl;
}

