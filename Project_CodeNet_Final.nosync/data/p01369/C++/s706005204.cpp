#include <bits/stdc++.h>
using namespace std;

const char* r = "hijklmnopuy";

int main()
{
    char s[64];

    while (scanf("%s", s), *s != '#'){
        bool now_right;
        int cnt = 0;
        int len = strlen(s);

        now_right = binary_search(r, r + 11, s[0]);
        for (int i = 1; i < len; i++){
            if (binary_search(r, r + 11, s[i]) != now_right){
                cnt++;
                now_right = !now_right;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}