#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
    Int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    Int all_A_B, all_AB, A_or_B_and_AB1, A_or_B_and_AB2, ans;
  
  	all_A_B = X * A + Y * B;
  
  	all_AB = min(X,Y) * 2 * C + (X + Y - 2 * min(X,Y)) * 2 * C;
  
  	A_or_B_and_AB1 = min(X,Y) * 2 * C + (X - min(X,Y)) * A + (Y - min(X,Y)) * B;
  
  	A_or_B_and_AB2 = min(X,Y) * 2 * C + (X - min(X,Y)) * 2 * C + (Y - min(X,Y)) * 2 * C;
  
  	ans = min(all_A_B, min(all_AB, min(A_or_B_and_AB1, A_or_B_and_AB2)));
  
  	cout << ans << endl;



}