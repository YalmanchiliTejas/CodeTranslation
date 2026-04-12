#include <iostream>
using namespace std;

long long mx(long long a, long long b)
{
    if(a < b) return b;
    return a;
}

int main()
{
    long long N;
    cin >> N;

    long long a[N+1];
    a[0] = 0;
    for(long long i = 1; i <= N; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }

    long long first[N+1][N+1], second[N+1][N+1];
    for(long long i = 1; i <= N; i++)
    {
        first[i][i] = a[i] - a[i-1];
        second[i][i] = 0;
        //cout << first[i][i] << "/" << second[i][i] << ' ';
    }
    //cout << '\n';
    for(long long l = 2; l <= N; l++)
    {
        for(long long i = 1; i+l-1 <= N; i++)
        {
            long long j = i+l-1;
            //cout << first[i][j] << "/" << second[i][j] << ' ';
            first[i][j] = mx(a[i] - a[i-1] + second[i+1][j], a[j] - a[j-1] + second[i][j-1]);
            second[i][j] = a[j] - a[i-1] - first[i][j];
        }
        //cout << '\n';
    }
    cout << first[1][N] - second[1][N] << '\n';
    return 0;
}