#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    if (n < 2)  {
        cout << 0;
        return  0;
    }

    int L = 1e9;
    int R = 0;

    vector<ii>  P;

    for(int i = 0 ; i < n ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;

        if (x > y)  swap(x,y);

        L = min(L,x);
        R = max(R,y);

        P.pb(ii(x,y));
    }

    int Rmin = L, Rmax = 0;
    int Bmax = R, Bmin = 1e9;

    for(int i = 0 ; i < n ; ++i)    {
        Rmax = max(Rmax,P[i].X);
        Bmin = min(Bmin,P[i].Y);
    }
    ll  ans = 1ll * (Rmax - Rmin) * (Bmax - Bmin);

    sort(all(P));

    multiset<int> S;

    for(ii  A : P)
        S.insert(A.X);

    ans = min(ans,1ll * (R - L) * (P[n - 1].X - P[0].X));

    for(ii  A : P)  {
        S.erase (S.find(A.X));
        S.insert(A.Y);

        ans = min(ans,1ll * (R - L) * ((*--S.end()) - (*S.begin())));
    }
    cout << ans << endl;
}