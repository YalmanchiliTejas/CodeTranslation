#include <bits/stdc++.h>
using namespace std;  

int X,Y,Z;

int main(int argc, char const *argv[])
{
   // freopen("in.txt", "r", stdin);
    while(~scanf("%d%d%d", &X, &Y, &Z)) {
        X -= Z;
        printf("%d\n", X/(Y+Z));
    }
    return 0;
}