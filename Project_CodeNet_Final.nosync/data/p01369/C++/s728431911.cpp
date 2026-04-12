#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int) (n); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
char r[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};

int main(){
  string n;
  while(cin >> n and n != "#"){
    int res = 0;
    int code = 0;
    REP(i, n.size()){
      bool isright = false;
      REP(j, 11) if(n[i]==r[j]) isright = true;
      if((code == -1 and isright == true) or (code == 1 and isright == false)) res++;
      code = (isright ? 1 : -1);
    }
    cout << res << endl;
  }
}