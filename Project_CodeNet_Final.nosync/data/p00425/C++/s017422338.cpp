#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int main() {
    while(true) {
        int n; scanf("%d\n", &n);
        if(n==0) break;
        int die[] = {0,1,2,3,4,5};
        int dsum = 1;
        for(int i = 0; i < n; i++) {
            char command[20]; scanf("%s\n", command);
            if(command[0]=='N') {
                swap(die[0],die[1]); swap(die[1],die[5]); swap(die[5],die[4]);
            } else if(command[0]=='E') {
                swap(die[0],die[3]); swap(die[3],die[5]); swap(die[5],die[2]);
            } else if(command[0]=='W') {
                swap(die[0],die[2]); swap(die[2],die[5]); swap(die[5],die[3]);
            } else if(command[0]=='S') {
                swap(die[0],die[4]); swap(die[4],die[5]); swap(die[5],die[1]);
            } else if(command[0]=='R') {
                swap(die[1],die[2]); swap(die[2],die[4]); swap(die[4],die[3]);
            } else if(command[0]=='L') {
                swap(die[2],die[1]); swap(die[1],die[3]); swap(die[3],die[4]);
            }
            //printf("[%d,%d,%d,%d,%d,%d]\n",die[0],die[1],die[2],die[3],die[4],die[5]);
            dsum += die[0]+1;
        }
        printf("%d\n", dsum);
    }
    return 0;
}