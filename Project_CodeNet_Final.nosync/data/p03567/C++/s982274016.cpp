#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
cin >> str;
for (int i = 1; i < str.size(); i++) {
    if(str[i-1] =='A' && str[i]=='C') 
{printf("Yes\n"); return 0;}
}
printf("No\n");
return 0;
}