#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void) {
    int A,B,C,X,Y, ans=0;
    cin >> A >> B >> C >> X >> Y;
    int tmp_A=0;
    int tmp_B=0;
    int tmp_C=0;
    bool ABC_flag = true; //(A+B)と2*Cどっちが安いか
    if(A+B < 2*C) ABC_flag = false;
    bool calc_flag = true;

    int tmp_XY;
    bool XY_flag = true;
    if(ABC_flag){
      if(X>Y){
          tmp_C += 2*Y;
          tmp_XY = X-Y;
      }
      else{
          tmp_C += 2*X;
          tmp_XY = Y-X;
          XY_flag =false;
      }
    }
    else{
      tmp_A += X;
      tmp_B += Y;
      calc_flag = false;
    }

    if(calc_flag){
      if(XY_flag){
        if(A*tmp_XY > 2*C*tmp_XY)  tmp_C += 2*tmp_XY;
        else                       tmp_A += tmp_XY;
      }
      else{
        if(B*tmp_XY > 2*C*tmp_XY)  tmp_C += 2*tmp_XY;
        else                       tmp_B += tmp_XY;
      }
    }

    ans = A*tmp_A + B*tmp_B + C*tmp_C;
    cout << ans << endl;

    return 0;
}
