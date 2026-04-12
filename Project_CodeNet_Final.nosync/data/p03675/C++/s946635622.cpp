#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (int &a: A)
        scanf("%d", &a);
    vector<int> B(n);
    for (int i=0; i<n; i++)
        B[i%2==0 ? i/2 : n-i/2-1] = A[n-i-1];
    for (int i=0; i<n; i++)
        printf("%d%s", B[i], i==n-1 ? "\n" : " ");
}
