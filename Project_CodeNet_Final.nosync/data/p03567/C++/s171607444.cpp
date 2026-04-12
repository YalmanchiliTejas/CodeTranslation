/**
  *  Worg
  */
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

//FILE *fin = freopen("main.in", "r", stdin); FILE *fout = freopen("main.out", "w", stdout);

int main() {
    char s[10]; scanf("%s", s);

    for(int i = 0; i < (int)std::strlen(s) - 1; i++) {
        if(s[i] == 'A' && s[i + 1] == 'C') {
            printf("Yes\n"); return 0;
        }
    }
	printf("No\n"); return 0;
}
