  #include <bits/stdc++.h> 
  #include <math.h>
  using namespace std;
  using ll = long long;
  #define rep(i,n) for (int i = 0; i < (n); ++i)

  int main()
  {
	string s;
    cin >> s;
    if((s.find("A") != string::npos) && s.find("B") != string::npos) {
      cout << "Yes" << endl;
    }
    else
      cout << "No" << endl;
    return 0;
  }
