#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> stk[100];

int main(void) {
    int d;

    scanf("%d",&d);
    while(true) {
        char com[10];
        scanf("%s",com);
        if(!strcmp(com, "quit")) break;
        if(!strcmp(com, "pop")) {
            int i;
            scanf("%d", &i);
            printf("%c\n", stk[i].back());
            stk[i].pop_back();
        }
        if(!strcmp(com, "push")) {
            int i;
            char c[2];
            scanf("%d%s", &i, c);
            stk[i].push_back(c[0]);
        }
        if(!strcmp(com, "move")) {
            int i,j;
            scanf("%d%d", &i, &j);
            stk[j].push_back(stk[i].back());
            stk[i].pop_back();
        }
    }
    return 0;
}