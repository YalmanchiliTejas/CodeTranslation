#include <iostream>
#include <string>
#include <climits>
#include <cstring>


using namespace std;


int main(void)
{
     int N;
     string s;
     int count[50][26];

     for (int i = 0; i < 50; i++)
         for (int j = 0; j < 26; j++)
             count[i][j] = 0;

     cin >> N;
     for (int i = 0; i < N; i++) {
         cin >> s;
         for (auto it = s.begin(); it != s.end(); ++it) {
             count[i][*it - 'a']++;
         }
     }

     string ans = "";
     for (int i = 0; i < 26; i++) {
         int min = INT_MAX;
         for (int j = 0; j < N; j++) {
             if (min > count[j][i])
                 min = count[j][i];
         }
         ans += string(min, 'a' + i);
     }

     cout << ans << endl;

     return 0;
}
