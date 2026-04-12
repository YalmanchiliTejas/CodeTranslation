#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long LL;
stack <LL> num;
int pre[300];
char str[100];
void calc (char op) {
     int u = num.top(); num.pop();
     int v = num.top(); num.pop();
     if (op == '+')
        num.push(u+v);
     else if (op == '*')  
        num.push(u*v) ;   
}
LL solve1 (void) {
   int n = strlen(str);
   while ( !num.empty() )
        num.pop();
   stack <char> stk;
   for (int i=0;i<n;++i) 
       if ('0'<= str[i] && str[i]<='9')
          num.push(str[i]-'0');
       else {
          while ( !stk.empty() && pre[stk.top()] > pre[str[i]] ) {
                calc (stk.top());
                stk.pop();  
          }
          stk.push(str[i]);
       }   
   while ( !stk.empty() ) {
         calc(stk.top());
         stk.pop();
   }
   return num.top();      
}
LL solve2 (void) {
   LL sum = str[0]-'0';
   int n = strlen(str);
   for (int i=1;i<n;++i)
      if (str[i] == '+')
        sum += str[i+1]-'0';
      else if ( str[i]=='*' )
        sum *= str[i+1]-'0';
   return sum;        
}
int main(void) {
    int bod_ans;
    pre['+'] = 1;
    pre['*'] = 2;
    while ( scanf("%s",str)==1 ) {
          scanf ("%lld",&bod_ans); 
          LL ans1 = solve1();
          LL ans2 = solve2();
          if (ans1 == bod_ans && ans2 == bod_ans)
            puts("U");
          else if (ans1 == bod_ans)
            puts("M");
          else if (ans2 == bod_ans)
            puts("L");
          else
            puts("I");
    }
    return 0;
}