#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 200100;
const int offset = (1<<18);
const long long int inf = 1e18;

int n, m;

vector <vector <pair <int, int> > > izb;
vector <pair <int ,int> > vpii;

long long int dp[maxn];
long long int rj = 0;

struct tournament
{
    long long int maxi[2 * offset];
    long long int prop[2 * offset];
    void build()
    {
        REP(i, 0, 2 * offset) {maxi[i] = 0; prop[i] = 0;}
        return;
    }
    void saljiprop(int cvor)
    {
        int l = cvor * 2, r = cvor * 2 + 1;
        prop[l] += prop[cvor];
        maxi[l] += prop[cvor];
        prop[r] += prop[cvor];
        maxi[r] += prop[cvor];
        prop[cvor] = 0;
        return;
    }
    void update(int cvor, int a, int b, int l, int r, long long int kolko)
    {
        //cout << cvor << " " << a << " " << b << " " << l << " " << r << " " << kolko << endl;
        if(l > b || r < a) return;
        if(l >= a && r <= b)
        {
            prop[cvor] += kolko;
            maxi[cvor] += kolko;
            return;
        }
        saljiprop(cvor);
        int mid = (l + r) / 2;
        update(cvor * 2, a, b, l, mid, kolko);
        update(cvor * 2 + 1, a, b, mid + 1, r, kolko);
        maxi[cvor] = max(maxi[cvor * 2], maxi[cvor * 2 + 1]);
        return;
    }
    long long int dajmax(int cvor, int a, int b, int l, int r)
    {
        if(l > b || r < a) return -inf;
        if(l >= a && r <= b) return maxi[cvor];
        saljiprop(cvor);
        int mid = (l + r) / 2;
        return max(dajmax(cvor * 2, a, b, l, mid), dajmax(cvor * 2 + 1, a, b, mid + 1, r));
    }
}T;

int main()
{
    T.build();
    int l, r, a;
    scanf("%d%d", &n, &m);
    izb.insert(izb.begin(), n, vpii);
    REP(i, 0, m)
    {
        scanf("%d%d%d", &l, &r, &a);
        l--; r--;
        izb[r].push_back(make_pair(l, a));
        T.update(1, l, offset - 1, 0, offset - 1, -a);
    }
    REP(i, 0, n)
    {
        dp[i] = -T.dajmax(1, i, i, 0, offset - 1);
        //cout << dp[i] << endl;
        dp[i] = max(dp[i], dp[i] + T.dajmax(1, 0, i - 1, 0, offset - 1));
        T.update(1, i, i, 0, offset - 1, dp[i]);
        REP(j, 0, (int)izb[i].size())
        {
            T.update(1, izb[i][j].first, offset - 1, 0, offset - 1, izb[i][j].second);
        }
        rj = max(rj, dp[i]);
    }
    printf("%lld\n",rj);
    return 0;
}
