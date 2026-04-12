#include <bits/stdc++.h>

using namespace std;

int n, ar[200005], t[200005], s, g;

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", t+i);
        ar[i] = t[i];
    }
    sort(ar+1, ar+n+1);
    s = ar[n/2];
    g = ar[n/2+1];
    for(int i=1;i<=n;i++){
        if(t[i]<=s) printf("%d\n", g);
        else printf("%d\n", s);
    }

    return 0;
}
