#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main() {
   int n;
   cin >> n;
   string a[n], cahr, ans = "";
   string alfabets[26] = {"a", "b", "c", "d", "e", "f", "g", "h","i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
   map<string, int> alfamap, gotalfamap;

   for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int i = 0; i < 26; i++) {
         cahr = alfabets[i];
         gotalfamap[cahr] = 0;
      }
      for (int j = 0; j < a[i].length(); j++) {
         cahr = a[i][j];
         if (i == 0) { // 1週目で初期化
            if (alfamap[cahr] == 0) {
               alfamap[cahr] = 1;
            }else {
              alfamap[cahr] += 1;
            }
         } else { // それ以降
            if (gotalfamap[cahr] == 0) {
               gotalfamap[cahr] = 1;
            } else {
               gotalfamap[cahr] += 1;
            }
         }         
      }
      
      for(auto itr = alfamap.begin(); itr != alfamap.end(); ++itr) {
         if (i != 0) {
            if (alfamap[itr->first] > gotalfamap[itr->first]) {
               alfamap[itr->first] = gotalfamap[itr->first];
            }
         }
         //std::cout << "key = " << itr->first           // キーを表示
            //<< ", val = " << itr->second << "\n";    // 値を表示
      }
      //cout << a[n] << endl;
   }

   for (int i = 0; i < 26; i++) {
      cahr = alfabets[i];
      for (int j = 0; j < alfamap[cahr]; j++) {
         ans += cahr;
      }
   }
   cout << ans << endl;
   



   //std::string o, e, ans = "";
/*
  for (int i = 0; i < e.length(); i++) {
     ans = ans + o[i] + e[i];
  }

  if (o.length() != e.length()) {
     ans = ans + o[(o.length() - 1)];
  }

  cout << ans << endl;
  */

}