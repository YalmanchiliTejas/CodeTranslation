#include<bits/stdc++.h>
using namespace std;
int n, m, p, q, r;
int ara[300000];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++) scanf("%d", &ara[i]);

    for(int i = n; i > 0; i -= 2){
        printf("%d ", ara[i]);
    }
    int i;
    if(n % 2 == 0) i = 1;
    else i = 2;

    for( ; i <= n; i += 2) printf("%d ", ara[i]);


    return 0;
}
