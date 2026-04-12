#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int M = 1e5 + 10;
int f[M];
int find(int x) {
    if(x == f[x]) return f[x];
    int tmp = find(f[x]);
    return f[x] = tmp;
}
struct TnT {
    int x , y , pos , num;
}T[M] , GT[M << 1];
bool cmp1(TnT a , TnT b) {
    return a.x < b.x;
}
bool cmp2(TnT a , TnT b) {
    return a.y < b.y;
}
bool cmp3(TnT a , TnT b) {
    return a.num < b.num;
}
int main() {
    int n;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d%d" , &T[i].x , &T[i].y);
        T[i].pos = i;
    }
    for(int i = 1 ; i <= n ; i++) f[i] = i;
    sort(T + 1 , T + 1 + n , cmp1);
    int cnt = 0;
    for(int i = 1 ; i < n ; i++) {
        GT[++cnt].x = T[i].pos , GT[cnt].y = T[i + 1].pos , GT[cnt].num = T[i + 1].x - T[i].x;
    }
    sort(T + 1 , T + 1 + n , cmp2);
    for(int i = 1 ; i < n ; i++) {
        GT[++cnt].x = T[i].pos , GT[cnt].y = T[i + 1].pos , GT[cnt].num = T[i + 1].y - T[i].y;
    }
    int sum = 0;
    sort(GT + 1 , GT + 1 + cnt , cmp3);
    for(int i = 1 ; i <= cnt ; i++) {
        GT[i].x = find(GT[i].x) , GT[i].y = find(GT[i].y);
        if(GT[i].x != GT[i].y) {
            f[GT[i].x] = GT[i].y;
            sum += GT[i].num;
        }
    }
    printf("%d\n" , sum);
    return 0;
}