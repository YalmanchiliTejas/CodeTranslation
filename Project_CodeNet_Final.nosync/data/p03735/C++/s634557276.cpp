#include<bits/stdc++.h>

using namespace std;

int minY, mini, maxi, curr, N, xx[200009], yy[200009], x[200009], y[200009], maX[200009], maY[200009], miY[200009], ind[200009];
long long ans;
vector < int > nrm;

bool cmp (int i, int j) {return xx[i] < xx[j];}
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), ans = 1000000000000000009LL;
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &xx[i], &yy[i]);
    if (xx[i] > yy[i]) swap (xx[i], yy[i]);
    ind[i] = i;
    nrm.push_back (xx[i]), nrm.push_back (yy[i]);
}
sort(nrm.begin(), nrm.end());
nrm.erase (unique (nrm.begin (), nrm.end ()), nrm.end ());
sort (ind + 1, ind + N + 1, cmp);
for (int i=1; i<=N; i++)
    x[i] = xx[ind[i]], y[i] = yy[ind[i]];
mini = nrm[0], maxi = nrm[nrm.size () - 1], minY = maxi + 2;
int i = 1;
for (auto& val : nrm)
{
    while (x[i] < val && i <= N)
    {
        if (y[i] > curr) curr = y[i];
        if (y[i] < minY) minY = y[i];
        i ++;
    }
    if (minY >= val)
    {
        int dr = max (x[N], curr);
        if (i > N) dr = curr;
        if (1LL * (dr - val) * (maxi - mini) < ans)
            ans = 1LL * (dr - val) * (maxi - mini);
    }
}
int st = mini, dr = x[N], dr2 = maxi, st2 = maxi;
for (int i=1; i<=N; i++)
    if (y[i] < st2)
        st2 = y[i];
if (1LL * (dr - st) * (dr2 - st2) < ans)
    ans = 1LL * (dr - st) * (dr2 - st2);
printf ("%lld\n", ans);
return 0;
}
