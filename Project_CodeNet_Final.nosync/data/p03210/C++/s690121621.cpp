#include <iostream>
#include <vector>


using namespace std;


void atcoder_beginner_contest999()
{
  string n;
  cin >> n;

  for (int i = 0; i < n.size(); ++i)
  {
    if (n[i] == '1') n[i] = '9';
    else if (n[i] == '9') n[i] = '1';
  }
  cout << n << "\n";
}


void programming_education()
{
  int n;
  cin >> n;
  
  if (n == 1)
  {
    cout << "Hello World\n";
    return;
  }
  else
  {
    int a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}

void discount_fare()
{
  int x, y;
  cin >> x >> y;

  cout << x + y / 2 << "\n";
}


void A_114()
{
  int x;
  cin >> x;

  if (x == 3 || x == 5 || x == 7) cout << "YES\n";
  else cout << "NO\n";
}



int main()
{
  //atcoder_beginner_contest999();
  //programming_education();
  //discount_fare();
  A_114();
}