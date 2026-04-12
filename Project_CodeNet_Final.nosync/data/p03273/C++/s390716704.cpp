#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1(){
   int h, w; cin >> h >> w;
   vector<vector<char>> a(h, vector<char>(w));
   rep(i, h) {
      rep(j, w) {
         cin >> a[i][j];
      }
   }

   set<int> allr;
   set<int> allc;

   rep(i, h) {
      bool f = true;
      rep(j, w) {
         if(a[i][j] != '.') {
            f = false;
         }
      }
      if(f) {
         allr.insert(i);
      }
   }

   rep(i, w) {
      bool f = true;
      rep(j, h) {
         if(a[j][i] != '.') {
            f = false;
         }
      }

      if(f) {
         allc.insert(i);
      }
   }

  /* for(auto itr = allr.begin(); itr != allr.end(); itr++) {
      cout << *itr << endl;
   }

   for (auto itr = allc.begin(); itr != allc.end(); itr++)
   {
      cout << *itr << endl;
   }
   */

  rep(i, h) {
      if(allr.find(i) == allr.end()) {
         rep(j, w) {
            if (allc.find(j) == allc.end()) {
               cout << a[i][j];
            }
         }
         cout << endl;
      }
   }

}

int main()
{
   solve1();
}