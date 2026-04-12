#include <bits/stdc++.h>

using namespace std;


int N, ans=0, last;

int main()
{
    cin>>N;
    vector <int> H(N);
    for (int i=0; i<N; i++)
    {
        cin>>H[i];
    }

    for (int i=0; i<N; i++)
    {
        int ok = 1;
        for (int j=0; j<i; j++)
        {
            if (H[j]>H[i])
            {
                ok=0;
            }
        }
        if (ok)
        {
            ans++;
        }
    }
    cout<<ans;
}
