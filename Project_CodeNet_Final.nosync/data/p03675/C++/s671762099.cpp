#include<bits/stdc++.h>

using namespace std;

int N, a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
if (N & 1)
{
    for (int i=N; i>=1; i-=2)
        printf ("%d ", a[i]);
    for (int i=2; i<=N; i+=2)
        printf ("%d ", a[i]);
}
else
{
    for (int i=N; i>=1; i-=2)
        printf ("%d ", a[i]);
    for (int i=1; i<=N; i+=2)
        printf ("%d ", a[i]);
}
printf ("\n");
return 0;
}
