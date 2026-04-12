#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>

bool adj_mat[8][8];
int perms[8] = {0, 1, 2, 3, 4, 5, 6, 7};
using namespace std;

int main(){
   int N;
   int M;
   cin >> N >> M;
   for(int i = 0; i < M; i++){
       int a;
       int b;
       cin >> a >> b;
       adj_mat[a - 1][b - 1] = true;
       adj_mat[b - 1][a - 1] = true;
   }

    int ans = 0;
   do {
       bool good = true;
       if(perms[0] != 0){
           continue;
       }
       for(int i = 0; i < N - 1; i++){
           if(!adj_mat[perms[i]][perms[i + 1]]){
               good = false;
               break;
           }
       }
       if(good){
           ans ++;
       }
   } while(next_permutation(perms, perms + N));

    cout << ans << endl;
   return 0;
}
