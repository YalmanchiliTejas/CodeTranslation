#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int sum = 100*a + 10*b + c;
    if(sum%4 == 0) puts("YES");
    else puts("NO");
    return 0;
}
