#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
using namespace std;

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    int counter = 0;
    REP (i, H) {
        string input;
        cin >> input;
        REP (j, input.size()) {
            if (input[j] == '#') counter++;
        }
    }
    if (counter == H + W - 1) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }
}