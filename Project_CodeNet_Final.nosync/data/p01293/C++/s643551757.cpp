#include <bits/stdc++.h>

using namespace std;

int conv[128];

bool stronger(char *t1, char *t2, char p1, char p2)
{
    if (t1[1] != t2[1] && (t1[1] == p1 || t1[1] == p2 || t2[1] == p2 || t2[2] == p2)){
        if (t1[1] == p1) return (0);
        if (t2[1] == p1) return (1);
        if (t1[1] == p2) return (0);
        return (1);
    }
    else {
        return (conv[t1[0]] < conv[t2[0]]);
    }
}

int main()
{
    for (int i = 2; i <= 9; i++) conv[i + '0'] = i;
    conv['T'] = 10, conv['J'] = 11, conv['Q'] = 12, conv['K'] = 13, conv['A'] = 14;
    
    char c[2];
    
    while (scanf("%s", c) && c[0] != '#'){
        char mp[4][13][3];
        
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 13; j++){
                scanf("%s", mp[i][j]);
            }
        }
        
        int whom = 0;
        int won[2] = {0};
        for (int i = 0; i < 13; i++){
            int next = whom;
            for (int j = whom, ctr = 1; ctr < 4; ctr++){
                int player = (j + ctr) % 4;
                if (stronger(mp[next][i], mp[player][i], c[0], mp[whom][i][1])){
                    next = player;
                }
            }
            whom = next;
            won[next & 1]++;
        }
        
        printf("%s %d\n", (won[0] > won[1] ? "NS" : "EW"), max(won[0], won[1]) - 6);
    }
    
    return (0);
}