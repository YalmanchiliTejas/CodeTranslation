#include <cstdio>

using namespace std;

int main() {
    char c;
    scanf("%c", &c);

    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return !printf("vowel\n");
    }

    printf("consonant\n");
    return 0;
}
