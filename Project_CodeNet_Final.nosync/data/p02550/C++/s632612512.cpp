#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    
    long long int N, X, M;
    cin >> N >> X >> M;
    unsigned long long int ans = 0;

    vector<int> la;
    long long int a = X;
    ans += a;
    std::vector<int>::iterator it; 
    for(int i = 1; i < N; ++i)
    {
        long long int at = (a*a)%M;
        it = std::find (la.begin(), la.end(), at); 
        if(it != la.end())
        {
            int ns = it - la.begin();
            int nm = la.size() - ns;
            long long int ss = (N-i)/nm;
            long long int sm = (N-i)%nm;
            for(int k = 0; k < sm; ++k)
            {
                ans += la[k+ns];
            }
            long long int dda = 0;
            for(int k = ns; k < la.size(); ++k)
            {
                dda += la[k];
            }
            ans += dda*ss;
            break;
        }
        ans += at;
        a = at;
        la.push_back(a);
    }

    cout << ans << endl;

    return 0;
}

