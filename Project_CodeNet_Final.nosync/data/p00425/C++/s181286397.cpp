#include <iostream>
using namespace std;

int main() {
  int n;
  int top, front, eside, temp, sum;
  string str;
  
  while(cin>>n, n) {
    // ティツヲツ凝」ツ?暗」ツつ凝・ツ?エテ」ツ?ョテァツ環カテヲツ?凝」ツつ津、ツソツ敕ヲツ個?」ツ?凖」ツつ凝」ツ?禿」ツ?ィテ」ツ?ァテ」ツつオテ」ツつ、テ」ツつウテ」ツδュテ」ツ?ョテ」ツ?凖」ツ?ケテ」ツ?ヲテ」ツ?ョテゥツ敖「テ」ツ?ョテァツ環カテヲツ?凝」ツ?古、ツソツ敕ヲツ個?」ツ?陛」ツつ古」ツつ?
    top = 1, front = 2, eside = 3; sum = top;
    for(int i = 0; i < n; i++) {
      cin >> str;
      if(str[0] == 'N') temp = top, top = front, front = 7-temp;
      if(str[0] == 'E') temp = eside, eside = top, top = 7-temp;
      if(str[0] == 'W') temp = top, top = eside, eside = 7-temp;
      if(str[0] == 'S') temp = front, front = top, top = 7-temp;
      if(str[0] == 'R') temp = front, front = eside, eside = 7-temp;
      if(str[0] == 'L') temp = eside, eside = front, front = 7-temp;
      sum += top;
    }
    cout << sum << endl;
  }

  return 0;
}