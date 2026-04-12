#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[64];
    char lf[] = "qwertasdfgzxcvb";
    
    while (scanf("%s", str) && str[0] != '#'){
        int ct = 0;
        
        for (int i = 1; str[i]; i++){
            bool j1 = false, j2 = false;
            for (int j = 0; lf[j]; j++){
                if (str[i] == lf[j]) j1 = true;
                if (str[i - 1] == lf[j]) j2 = true;
            }
            
            ct += (j1 ^ j2);
        }
        
        printf("%d\n", ct);
    }
    
    return (0);
}