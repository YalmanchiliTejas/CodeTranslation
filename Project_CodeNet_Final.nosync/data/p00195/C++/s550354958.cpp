#include <iostream>
#include <cstdio>
using namespace std;
int main(void) {
  int s1[5], s2[5], total[5], max, shop;
  
  while(1) {
    max = 0;
    cin >> s1[0] >> s2[0];
    total[0] = s1[0] + s2[0];
    if(s1[0] == 0 && s2[0] == 0) break;
    for(int i = 1 ; i < 5 ; i++) {
      cin >> s1[i] >> s2[i];
      total[i] = s1[i] + s2[i];
    }
    
    for(int i = 0 ; i < 5 ; i++) {
      if(total[i] > max) { max = total[i]; shop = i; }
    }

    if(shop == 0) cout << 'A' << ' ' << total[0] << endl;
    if(shop == 1) cout << 'B' << ' ' << total[1] << endl;
    if(shop == 2) cout << 'C' << ' ' << total[2] << endl;
    if(shop == 3) cout << 'D' << ' ' << total[3] << endl;
    if(shop == 4) cout << 'E' << ' ' << total[4] << endl;
  }
  return 0;
}