#include <bits/stdc++.h>
using namespace std;
long long n, i, rmin, rmax, bmin, bmax, a[200100], b[200100], ans;
vector <pair <long long, long long> > v;
int main()
{


    cin >> n;

    for(i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    rmin = INT_MAX; bmin = INT_MAX;
    rmax = 0; bmax = 0;
    for(i = 0; i < n; ++i)
    {
        if(a[i] > b[i])
            swap(a[i], b[i]);
        v.push_back(make_pair(a[i], b[i]));
        rmin = min(rmin, a[i]);
        rmax = max(rmax, a[i]);
        bmax = max(bmax, b[i]);
        bmin = min(bmin, b[i]);
    }
    ans = (rmax - rmin) * (bmax - bmin);
    sort(v.begin(), v.end());
    rmax = bmax;
    bmin = INT_MAX; bmax = 0;
    set <pair <long long, long long> > st;
    set <pair <long long, long long> > :: iterator i1, i2;
    for(i = 0; i < v.size(); ++i)
        st.insert(v[i]);
    bmin = v[0].first; bmax = v.back().first;
    ans = min(ans, (bmax - bmin) * (rmax - rmin));
    for(i = 0; i < v.size(); ++i)
    {
        st.erase(v[i]);
        st.insert(make_pair(v[i].second, v[i].first));
        i1 = st.begin(); i2 = st.end(); i2--;
        bmin = (i1 -> first); bmax = (i2 -> first);
        ans = min(ans, (rmax - rmin) * (bmax - bmin));
    }
    cout << ans;

return 0;
}
