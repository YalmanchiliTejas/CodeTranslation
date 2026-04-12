#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N, S;
    cin>>N>>S;
    vector<int> A(N);
    for (int &a: A)
        cin>>a;

    long long M = 998244353;
    long long ans = 0;
    vector<long long> T(S);
    T[0] = 1;
    for (int i=0; i<N; i++)
    {
        T[0] = i+1;
        for (int j=S-1; j>=0; j--)
        {
            if (j+A[i]==S)
            {
                ans += T[j]*(N-i);
                ans %= M;
            }
            if (j+A[i]<S)
            {
                T[j+A[i]] += T[j];
                T[j+A[i]] %= M;
            }
        }
    }
    cout<<ans<<endl;
}
