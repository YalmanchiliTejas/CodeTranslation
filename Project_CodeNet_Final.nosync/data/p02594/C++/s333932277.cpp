#include <iostream>
#include <vector>

using namespace std;

void abc_170a();

void abc_171a();

void abc_172a();

void abc_173a();

void abc_174a();

int main()
{
  //abc_170a();
  //abc_171a();
  //abc_172a();
  //abc_173a();
  abc_174a();

}

void abc_170a()
{
  vector<int> x(5);
  for (int i = 0; i < 5; ++i) cin >> x[i];

  for (int i = 0; i < 5; ++i)
  {
    if (x[i] == 0)
    {
      cout << i + 1 << "\n";
      return;
    }
  }
}


void abc_171a()
{
  char c;
  cin >> c;

  if (c == tolower(c)) cout << "a\n";
  else cout << "A\n";
}

void abc_172a()
{
  int a;
  cin >> a;

  cout << a + a * a + a * a * a << "\n";
}

void abc_173a()
{
  int N;
  cin >> N;

  if (N % 1000) cout << 1000 - N % 1000 << "\n";
  else cout << "0\n";
}

void abc_174a()
{
  int x;
  cin >> x;

  if (x >= 30) cout << "Yes\n";
  else cout << "No\n";
}
