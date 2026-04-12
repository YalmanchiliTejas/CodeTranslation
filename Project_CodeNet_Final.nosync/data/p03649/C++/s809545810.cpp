#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> a(N);
    for (long long &t: a)
        cin>>t;
    long long K = 0;
    while (true)
    {
        bool up = false;
        for (int i=0; i<N; i++)
        if (a[i]>N-1)
        {
            up = true;
            long long c = a[i]/N;
            K += c;
            for (int j=0; j<N; j++)
                if (j==i)
                    a[j] -= c*N;
                else
                    a[j] += c;
        }
        if (!up)
            break;
    }
    cout<<K<<endl;
}
