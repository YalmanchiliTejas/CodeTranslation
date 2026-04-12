#include <bits/stdc++.h>

using namespace std;

int main()
{
  char express[20];
  int bob;
  scanf("%s\n%d", express, &bob);
  strcat(express, "E");
  stack<int> stk;
  char op;
  int num;
  int miscalc;
  sscanf(express, "%d%s", &miscalc, express);
  stk.push(miscalc);
  while(strcmp(express, "E") != 0){
    sscanf(express, "%c%d%s", &op, &num, express);
    if(op == '*'){
      miscalc *= num;
      int x = stk.top(); stk.pop();
      stk.push(x*num);
    } else {
      miscalc += num;
      stk.push(num);
    }
  }
  int corcalc = 0;
  while(!stk.empty()){
    corcalc += stk.top(); stk.pop();
  }
  if(bob == corcalc && bob != miscalc) cout << "M" << endl;
  if(bob != corcalc && bob == miscalc) cout << "L" << endl;
  if(bob == corcalc && bob == miscalc) cout << "U" << endl;
  if(bob != corcalc && bob != miscalc) cout << "I" << endl;
  return 0;
}