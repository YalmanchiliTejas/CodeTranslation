#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int pay = N*800;
    int get = N/15*200;
    printf("%d\n", pay-get);
    return 0;
}