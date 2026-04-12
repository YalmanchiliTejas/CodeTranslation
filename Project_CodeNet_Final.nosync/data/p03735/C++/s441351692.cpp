#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef long long LL;

const int NMAX = 2e5 + 5;

int N;
int a[NMAX], b[NMAX];

multiset<int> st;

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
    }

    int mxa = 0, mna = 1 << 30, mxb = 0, mnb = 1 << 30;
    for(int i = 1; i <= N; i++)
    {
        mxa = max(mxa, a[i]);
        mxb = max(mxb, b[i]);
        mna = min(mna, a[i]);
        mnb = min(mnb, b[i]);
    }

    LL ans = 1LL * (mxa - mna) * (mxb - mnb);

    int mn = min(mna, mnb), mx = max(mxa, mxb);
    bool ok = false;
    int cntmn = 0, cntmx = 0;
    int idmn = 0, idmx = 0;
    for(int i = 1; i <= N; i++)
    {
        if(a[i] == mn) cntmn++;
        if(b[i] == mx) cntmx++;
        if(a[i] == mn && b[i] == mx)    continue;
        ok = true;
        if(a[i] == mn)  idmn = i;
        if(b[i] == mx)  idmx = i;
    }
    if(cntmn > 1 || cntmx > 1) ok = true;

    if(!idmn)   for(int i = 1; i <= N; i++) if(a[i] == mn)  { idmn = i; break; }
    if(!idmx)   for(int i = 1; i <= N; i++) if(b[i] == mx && i != idmn) { idmx = i; break; }
    if(!idmx) { idmn = 0; for(int i = 1; i <= N; i++) if(b[i] == mx) { idmx = i; break; } for(int i = 1; i <= N; i++) if(a[i] == mn && i != idmx)  { idmn = i; break; } }

    if(!ok) { printf("%lld\n", ans); exit(0); }

    vector<int> ord;
    st.insert(b[idmn]); st.insert(a[idmx]);
    for(int i = 1; i <= N; i++)
        if(i != idmn && i != idmx)
        {
            ord.push_back(i);
            st.insert(a[i]);
        }
    sort(ord.begin(), ord.end(),
         [](int x, int y) { if(a[x] == a[y]) return b[x] < b[y]; return a[x] < a[y]; });

    int mnn = *(st.rbegin()) - *(st.begin());
    for(auto id: ord)
    {
        st.erase(st.find(a[id]));
        st.insert(b[id]);

        int val = *(st.rbegin()) - *(st.begin());
        mnn = min(mnn, val);
    }

    ans = min(ans, 1LL * mnn * (mx - mn));

    printf("%lld\n", ans);

    return 0;
}
