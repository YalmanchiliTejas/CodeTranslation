#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{



    int n; cin>>n;
    vector<P> v(n);
    map<int,int> cnt;
    for(int i = 0 ; i<n ; i++)
    {
        int x;
        cin >> x;
        v[i] = {x,i};
    }
    sort(v.begin() , v.end());
    int curMed = (n-1)/2;
    vector<int> ans(n);
    for(int i = 0 ; i<n ; i++)
    {
        int idx = v[i].second;
        if(i==0)
        {
            int x = v[curMed+1].first;
            ans[idx] = x;
        }
        else if(i>curMed)
        {
                int x = v[curMed].first;
                ans[idx] = x;
        }
        else if(i<=curMed)
        {
            ans[idx] = v[curMed+1].first;
        }

        else if(i==n-1)
        {
            ans[idx] = v[curMed+1].first;
        }
    }

    for(auto x : ans)
        cout<<x<<endl;



    return 0;
}
