#include <cstdio>

using namespace std;

char litere[5];

int main()
{
    char ch;
    int len = 0;
    scanf("%c", &ch);
    while(ch != '\n'){
        len++;
        litere[len] = ch;
        scanf("%c", &ch);
    }
    bool ok = 0;
    for(int i = 1; i < len; i++){
        if(litere[i] == 'A' && litere[i + 1] == 'C'){
            ok = 1;
            break;
        }
    }
    if(ok)
        printf("Yes");
    else
        printf("No");
    return 0;
}
