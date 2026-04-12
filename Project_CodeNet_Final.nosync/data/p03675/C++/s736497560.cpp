#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> arr;
int main () {
    int N;
    scanf("%d", &N);
    arr.resize(N+1);
    for(int i=1;i<=N;i++) {
        scanf("%d", &arr[i]);
    }
    
    if(N==1) {
        printf("%d", arr[1]);
    } else if(N==2) {
        printf("%d %d", arr[2], arr[1]);
    } else {
        int step = (N+1)/2;
        
        int idx = N;
        for(int i=1;i<=step-1;i++) {
            printf("%d ", arr[idx]);
            idx -=2;
        }
        
        if(N%2) {
            printf("%d %d ", arr[1], arr[2]);
        } else {
            printf("%d %d ", arr[2], arr[1]);
        }
        
        idx = 3+N%2;
        for(int i=1;i<=step-1-N%2;i++) {
            printf("%d ", arr[idx]);
            idx += 2;
        }
    }
    return 0;
}