#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int> >

template <class X> void print(X Target){ cout << Target << '\n'; }

signed main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<stack<char> > block(n);
  
  string input;
  while (cin >> input, input != "quit"){
    if (input == "pop"){
      int num;
      cin >> num;
      print(block[num - 1].top());
      block[num - 1].pop();
    }
    else if (input == "push"){
      int num;
      char c;
      cin >> num >> c;
      block[num - 1].push(c);
    }
    else if (input == "move"){
      int num1, num2;
      cin >> num1 >> num2;
      block[num2 - 1].push(block[num1 - 1].top());
      block[num1 - 1].pop();
    }
  }

  return (0);
}