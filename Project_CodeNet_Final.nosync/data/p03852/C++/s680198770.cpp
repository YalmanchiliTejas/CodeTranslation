#include <cstdio>
#include <string>

using namespace std;

int main() {
    string s = "aiueo";
    char c;
    scanf("%c", &c);
    if (s.find(c) != string::npos) printf("vowel\n");
    else printf("consonant\n");
    return 0;
}
