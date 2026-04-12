#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> A(N);
    for (long long &a: A)
        cin>>a;

    int d = N%2==0 ? 2 : 3;
    vector<vector<long long>> T(d, vector<long long>(N/2, -1000000000000000LL));
    for (int i=0; i<d; i++)
        T[i][0] = A[i];
    for (int i=1; i<N/2; i++)
        for (int j=0; j<d; j++)
            for (int k=0; k<=j; k++)
                T[j][i] = max(T[j][i], T[k][i-1]+A[2*i+j]);
    long long ans = -1000000000000000LL;
    for (int i=0; i<d; i++)
        ans = max(ans, T[i][N/2-1]);
    cout<<ans<<endl;
}
