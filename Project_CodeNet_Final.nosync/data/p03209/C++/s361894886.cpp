#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define x first
#define y second
#define NMAX 54

int n;
long long k, v[NMAX];

void precomputeSizes() {
    v[0] = 1;
    for(int i = 1; i <= n; i++) {
        v[i] = 2 * v[i - 1] + 3;
      //  printf("%d %lld\n", i, v[i]);
    }
}

long long countPatty(int burger_level, long long height_level) {
    if(!burger_level)
        return 1;
        
    if(height_level == 1)    
        return 0;
        
    if(height_level <= v[burger_level - 1] + 1)
        return countPatty(burger_level - 1, height_level - 1);
        
    if(height_level <= v[burger_level - 1] + 2)
        return (1LL << burger_level);
        
    if(height_level < v[burger_level])
        return (1LL << burger_level) + countPatty(burger_level - 1, height_level - 2 - v[burger_level - 1]);

    return (1LL << (burger_level + 1)) - 1;
}

int main () {
    
    scanf("%d%lld",&n,&k);
    
    precomputeSizes();
    printf("%lld\n", countPatty(n, k));
    
    return 0;
}

