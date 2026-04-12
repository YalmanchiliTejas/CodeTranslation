#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define scint(x) scanf("%d", &x)
#define sclng(x) scanf("%ld", &x)
typedef long long ll;

int main(){
    int X;
    scint(X);
    if(X == 7 || X == 5 || X == 3){
        printf("YES\n");
    }else{
        printf("NO");
    }
    return 0;
}