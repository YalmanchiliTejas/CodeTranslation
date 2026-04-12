#include<iostream>
#include<fstream>
using namespace std;
long long sequence[3005] = {0};
long long maxSum = 0;
long long matrix[3005][3005] ;
int n;
void init()
{
    for(int i = 0; i < 3005; i++)
        sequence[i] = 0;
    for(int i = 0; i < 3005; i++)
        for(int j = 0; j < 3005; j++)
            matrix[i][j] = -1;
}
void read()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> sequence[i];
        maxSum = maxSum + sequence[i];
    }
}

long long dei(long long l, long long r)
{
    if(l > r)
        return 0;
    if(matrix[l][r] == -1)
    {
        long long a;
        long long b;
        if(matrix[l + 2][r] == -1)
            matrix[l +2][r] = dei(l + 2, r);
        if(matrix[l + 1][r - 1] == -1)
            matrix[l + 1][r-1] = dei(l + 1, r - 1);
        if(matrix[l ][r - 2] == -1)
            matrix[l][r -2] = dei(l , r - 2);
        if(matrix[l + 2][r] > matrix[l + 1][r - 1])
            a = matrix[l + 1][r - 1];
        else a = matrix[l + 2][r];
        if(matrix[l + 1][r - 1] > matrix[l ][r - 2])
            b = matrix[l ][r - 2];
        else b = matrix[l + 1][r - 1];
        if(sequence[l] + a < sequence[r] + b)
            matrix[l][r] = sequence[r] + b;
        else matrix[l][r] = sequence[l] + a;

    }
    return matrix[l][r];
}
int main()
{
    read();

    long long rez = dei(1, n);
    cout << 2 * rez - maxSum;
}