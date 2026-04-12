#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    vector<ll> B(N);
    if(N%2)
    {
        ll center = A[N/2];
        if(center - A[N/2-1] < A[N/2+1] - center)
        {
            B[0] = A[N/2-1];
            B[1] = A[N/2+1];
            for(int i=0, j=N/2+2, k=2; i<N/2-1; i++, j++, k+=2)
            {
                B[k] = A[i];
                B[k+1] = A[j];
            }
            B[N-1] = center;
        }
        else
        {
            B[0] = A[N/2+1];
            B[1] = A[N/2-1];
            for(int i=0, j=N/2+2, k=2; i<N/2-1; i++, j++, k+=2)
            {
                B[k] = A[j];
                B[k+1] = A[i];
            }
            B[N-1] = center;
        }
    }
    else
    {
        for(int i=N/2-1, j=N-1, k=0; i>=0; i--, j--, k+=2)
        {
            B[k] = A[i];
            B[k+1] = A[j];
        }
    }
    
    // for(auto b : B) cout << b << ' ';
    // cout << '\n';

    ll ans = 0;
    for(int i=1; i<N; i++)
    {
        ans += llabs(B[i] - B[i-1]);
    }
    cout << ans << endl;

    return 0;
}
