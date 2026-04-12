#include <cstdio>

using namespace std;

int main() {
    char ch = fgetc(stdin);
    int rez = 0;
    char s[7] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++)
        if(ch == s[i])
            rez = 1;
    if (rez == 1)
        printf("vowel");
    else
        printf("consonant");
    return 0;
}
