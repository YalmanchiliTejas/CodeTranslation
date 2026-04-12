#include        <bits/stdc++.h>
using   namespace       std;
typedef long long ll;

// int/long:            -2,147,483,648 - 2,147,483,647 (-2^31 <= int < 2^31)
// long/long long:      -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

#define INF (1<<30)
//1,073,741,824
//= 536,870,912 *2

#define MOD 1000000007

#define Rep0(i, n)      for (auto i=0; i<n; i++)
#define Rep1(i, n)      for (auto i=1; i<=n; i++)
#define Sort(P) sort(P.begin(), P.end())
#define Rev(P)  reverse(P.begin(), P.end())

int     main() {
        ll N;
        cin >>N;
        vector<ll> a(N, 0);
        Rep0(i, N)
                cin >>a.at(i);
        Sort(a);
        Rev(a);
        ll ANS=0;
        while (a.front()>=N) {
                ll A=a.front();
                ll NN=A/N;
                ANS +=NN;
                a.at(0)%=N;
                Rep1(i, N-1)
                        a.at(i) +=NN;
                Sort(a);
                Rev(a);
        }
        cout <<ANS <<endl;
        return 0;
}