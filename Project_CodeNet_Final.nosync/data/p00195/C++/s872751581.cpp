/* 
 * File:   main.cpp
 * Author: freebsd
 *
 * Created on 2014/08/28, 10:07
 */

#include <cstdio>

using namespace std;

int main() {
    while (true) {
        int s1[5] = {0}, s2[5] = {0};
        
        char store[5] = {'A', 'B', 'C', 'D', 'E'};
        
        for(int i = 0; i < 5; i++) {
            scanf("%d %d", &s1[i], &s2[i]);
            if(s1[0] == 0 && s2[0] == 0) return 0;
        }
        
        for(int i = 0; i < 5; i++) {
            s1[i] += s2[i];
        }
        
        int i = 0;
        char tempc;
        int max;
        
        max = s1[0];
        tempc = store[0];
        
        while(i != 4) {
            
            if(max < s1[i + 1]) {
                max = s1[i + 1];
                tempc = store[i + 1];
            }
            i++;
        }
        
        printf("%c %d\n", tempc, max);
    }
}