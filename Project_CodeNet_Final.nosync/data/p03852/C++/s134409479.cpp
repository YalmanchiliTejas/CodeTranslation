#include <cstdio>

using namespace std;

int main()
{
    char ch = getchar();

    if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o') printf("vowel\n");
    else printf("consonant\n");

    return 0;
}