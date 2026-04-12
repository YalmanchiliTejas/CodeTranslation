#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s;
int ans;
int main(){
    cin >> s;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'A')ans++;
    }
    if(ans == 1 or ans == 2)printf("Yes");
    else printf("No");
    return 0;
}