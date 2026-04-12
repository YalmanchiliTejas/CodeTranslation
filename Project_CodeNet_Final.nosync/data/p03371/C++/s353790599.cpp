#include<bits/stdc++.h>
using namespace std;
int A, B, C, X, Y;
int answer;
int judge(void){
 int over = C * max(X, Y) * 2;
 int under = max(C * Y * 2 + A * ( X - Y ),C * X * 2 + B * ( Y - X ));
 return min(over,under);
}

int main(){
 cin >> A >> B >> C >> X >> Y;

 if( (A + B) / 2 <  C){
  answer = A * X + B * Y;
 } else {
  answer = judge();
 }

 cout << answer << endl;
 return 0; 
};
