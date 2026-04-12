#include <bits/stdc++.h>

using namespace std;

int main() {

   string s;
   int pos[26] = {
       0, 0, 0, 0, 0, 0,
       0, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 0, 0,
       0, 0, 1, 0, 0, 0,
       1, 0
    };

   while(cin >> s, s != "#") {

        int cnt = 0;
        int lr = pos[s[0] - 'a'];

        for(int i = 1; i < s.size(); ++i) {

            if(pos[s[i] - 'a'] != lr) {
               ++cnt;
            }
            lr = pos[s[i] - 'a'];

        }

        cout << cnt << endl;

   }

}