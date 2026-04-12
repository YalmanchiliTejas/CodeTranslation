#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[4];
    scanf("%s", str);   

    if(strcmp(str, "AAA") == 0
      || strcmp(str, "BBB") == 0) {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    return 0;
}