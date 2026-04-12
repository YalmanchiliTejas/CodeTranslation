#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {
    int n;
    
    scanf("%d", &n);
    
    printf("%d", n * 800 - 200 * (n / 15));
    
}