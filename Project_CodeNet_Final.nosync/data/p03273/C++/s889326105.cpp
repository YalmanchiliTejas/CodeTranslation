#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int h, w;
     cin >> h >> w;
     vector<string> a(h);
     vector<bool> row(h, false);
     vector<bool> col(w, false);
     rep(i,0,h) cin >> a[i];
    
     rep(i,0,h){
       rep(j,0,w){
         if(a[i][j] == '#'){
           row[i] = true;
           col[j] = true;
         }
       }
     }

     rep(i,0,h){
       if(row[i]){
         rep(j,0,w){
           if(col[j]){
             cout << a[i][j];
           }
         }
         cout << endl;
       }
     }
    
     return 0;
}
