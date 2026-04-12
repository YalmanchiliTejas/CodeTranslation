#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int a = 0;
    string s;
    cin >> s;
    for(int i=0;i<3;i++){
        if(s[i] == 'A') a++;
    }
    if(a > 0 && a < 3) puts("Yes");
    else puts("No");
}
