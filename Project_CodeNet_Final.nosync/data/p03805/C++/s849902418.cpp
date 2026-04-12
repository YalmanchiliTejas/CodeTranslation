#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
    return n;
}

//greatest common divisor
unsigned long  gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}



int e[10][10] = {0};
int v[10] = {0};
int n, m;
int cnt = 0;

int dfs(int node){
    for (int i = 1; i <= n; i++){
        if (e[node][i] == 1 && v[i] == 0){
            v[i] = 1;
            dfs(i);
            v[i] = 0;
        }
    }
    int flag = 1;
    for (int i = 2; i <= n; i++){
        if (v[i] == 0){
            flag = 0;
        }
    }
    if (flag == 1){
        cnt++;
    }
    return 0;
}

int main(void){
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    v[1] = 1;
    dfs(1);
    

    printf("%d\n", cnt);




    return 0;
}
