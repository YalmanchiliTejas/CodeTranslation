#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string K;
    cin>>K;
    int D;
    cin>>D;

    vector<vector<long long>> A(K.size(), vector<long long>(D));
    vector<vector<long long>> B(K.size(), vector<long long>(D));
    long long M = 1000000007LL;

    for (int i=0; i<10; i++)
    {
        A[K.size()-1][i%D]++;
        if (i<=K[K.size()-1]-'0')
            B[K.size()-1][i%D]++;
    }

    for (int i=(int)K.size()-2; i>=0; i--)
    for (int j=0; j<D; j++)
    for (int k=0; k<10; k++)
    {
        int t = ((j-k)%D+D)%D;
        A[i][j] += A[i+1][t];
        A[i][j] %= M;
        if (k < K[i]-'0')
            B[i][j] += A[i+1][t],
            B[i][j] %= M;
        if (k == K[i]-'0')
            B[i][j] += B[i+1][t],
            B[i][j] %= M;
    }

    cout<<(B[0][0]-1+M)%M<<endl;
}
