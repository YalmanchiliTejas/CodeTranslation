#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int a, b, c;
int main(){
while(~scanf("%d %d %d", &a, &b, &c)) {
if((a * 100 + b * 10 + c) % 4 == 0) puts("YES");
else puts("NO");
}
}