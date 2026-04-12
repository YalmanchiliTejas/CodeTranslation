/*
    TASK: Medians
    GRADER: codersclub.in.th/problem/10275
    LANG: CPP
    AUTHOR: Parnikkapore
*/
#include<bits/stdc++.h>
using namespace std;

#define repeat(n) for(int i=0; i<n; i++)
#define dRepeat(n) for(int i=1; i<=n; i++)
#define dRepeatRev(n) for(int i=n; i>=1; i--)
#define inf 1000000 //1 million

/*
1 2 3 4 5 6
2 3 4 5 6 - 4
1 3 4 5 6 - 4
1 2 4 5 6 - 4
1 2 3 5 6 - 3
1 2 3 4 6 - 3
1 2 3 4 5 - 3
*/

int n, x[200010], y[200010];
int i,j,k;

int main(){
    scanf(" %d", &n);
    for(i=1; i<=n; i++){
        scanf(" %d", &x[i]);
        y[i]=x[i];
    }
    sort(x, x+i);
    int rmed = x[n/2];

    for(i=1; i<=n; i++){
        if(y[i]>rmed) printf("%d\n", x[n/2]);
        else          printf("%d\n", x[(n/2)+1]);
    }
    return 0;
}
