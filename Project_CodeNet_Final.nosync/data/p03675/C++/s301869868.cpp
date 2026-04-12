#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N), b(N);
    int t;
    for(int i=0; i!=N; i++){
        scanf("%d", &t);
        a[i]=t;
    }

    int i=N-1, j=0;
    for(; i>=0; i-=2){
        b[j++]=a[i];
    }
    if(i==-2) i=1;
    else i=0;
    for(; i<N; i+=2) b[j++]=a[i];

    for(i=0; i!=N; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}