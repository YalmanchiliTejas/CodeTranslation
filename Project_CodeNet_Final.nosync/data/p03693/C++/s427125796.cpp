#include <bits/stdc++.h>
using namespace std;

long long int A, B;

int main(){
    scanf("%lld%lld%lld", &A, &A, &B);
    puts(((A * 2 + B) & 3) ? "NO" : "YES");
    return 0;
}
