#include <iostream>
#include <cstdlib>
#include <math.h>
#define INF 1000000000

using namespace std;

int n, sum;

struct rIndices
{
    int val;
    int ind;
    int leftS;
} A[200001], sA[200001];

int compar(const void * a, const void * b)
{
  return ( (*(struct rIndices*)a).val - (*(struct rIndices*)b).val);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i].val;
        sA[i].val = A[i].val;
        A[i].ind = i;
    }

    qsort(A, n + 1, sizeof(struct rIndices), compar);

    for (int i = 1; i <= n; i++) sA[A[i].ind].leftS = (i <= n/2);

    int half = n / 2;
    for (int i = 1; i <= n; i++)
    {
        cout << A[half + sA[i].leftS].val << endl;
    }

    return 0;
}