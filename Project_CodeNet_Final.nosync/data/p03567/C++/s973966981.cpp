#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int64;
char s[15];
int main() {
    scanf("%s",s + 1);
    int l = strlen(s + 1);
    for(int i = 1 ; i < l ; ++i) {
        if(s[i] == 'A' && s[i + 1] == 'C') {
            puts("Yes");return 0;
        }
    }
    puts("No");return 0;
}