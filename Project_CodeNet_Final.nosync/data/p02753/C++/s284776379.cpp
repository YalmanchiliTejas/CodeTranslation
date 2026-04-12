#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define alpha_size 26



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);    
    
    set<char> s;
    for (int i = 0; i < 3; i++){
      char c;
      cin >> c;
      s.insert(c);
    }
    if (s.size() == 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}

