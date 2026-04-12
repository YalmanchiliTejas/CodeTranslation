#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int check(int _in){
    if(_in < 0) return 0;
    else return _in;
}

int main(){
    int a, b, ab, A, B;
    cin >> a >> b >> ab >> A >> B;
    
    int m = min(A,B);
    int case1 = A*a + B*b;
    
    int case2 = 2*A*ab + (check(B-A))*b;
    int case3 = 2*B*ab + (check(A-B))*a;
    cout << min(min(case1,case2), min(case2,case3)) <<endl;
return 0;
}
