#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define PB push_back
#define MP make_pair
#define SZ size()
#define Fr first
#define Sc second
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%I64d", &a)
#define sd(a) scanf("%lf", &a)
#define ss(a) scanf("%s", a)
#define debug(x) cout << #x << ": " << x << endl
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long Long;
typedef pair <int, int> Pii;
///<-------------------------------------------------END OF TEMPLATE-------------------------------------------------->

int main() {
   int N;
   deque <int> deq;
   si(N);
   for(int i = 0; i < N; i++) {
      int a;
      si(a);
      if(i & 1) deq.PB(a);
      else deq.push_front(a);
   }
   bool sp = false;
   while(!deq.empty()) {
      int x;
      if(N & 1) {
         x = deq.front();
         deq.pop_front();
      } else {
         x = deq.back();
         deq.pop_back();
      }
      if(sp) printf(" ");
      printf("%d", x);
      sp = true;
   }
   puts("");
}
