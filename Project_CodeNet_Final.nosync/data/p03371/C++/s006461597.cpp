#include <iostream>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
  int A,B,C,X,Y;
  int ANum,BNum,CNum;
  int result = INT_MAX;

  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;
  cin >> Y; 
  int loopMax = max(X,Y);  
  for (int i = 0; i <= loopMax; i++) {
    int tmpResult = 0;
    CNum = i * 2;
    ANum = max((X-i),0);
    BNum = max((Y-i),0);
    tmpResult = A*ANum+B*BNum+C*CNum;

    if (result > tmpResult) {
      result = tmpResult;
    }
  }
  cout << result << "\n";
  return 0;
}
