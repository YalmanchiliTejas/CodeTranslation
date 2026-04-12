#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;
#define ll long long

const int N = 1e5 + 5;
ll INF = 998244353;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x,m;
    cin>>n>>x>>m;

    unordered_map<ll,ll>hmap;

    vector<ll> pat;
    pat.push_back(x);
    hmap[x] = 0;

    ll prev = x;
    ll count = x;
    ll next;

    bool flag = false;
    int start, end;
    for(int i=1; i<n;i++)
    {
        next = (prev * prev) %m;
        if(hmap.find(next) != hmap.end())
        {
            flag = true;
            start = hmap[next];
            end = i-1;
            break;
        }
        //cout<<next<<" ";
        hmap[next] = i;
        pat.push_back(next);
        count += next;
        prev = next;
    }
    //cout<<endl;
    
    if(!flag)
    {
        cout <<count<<endl;
    }
    else
    {
        ll cycleSum = 0;
        for(int i = start; i<=end;i++)
        {
            cycleSum += pat[i];
        }

        ll rev = ( n - (end + 1))/ ( end - start + 1);
        count += cycleSum*rev;

        ll m = ( n - (end + 1))% ( end - start + 1);
        for(int i = 0; i<m;i++)
        {
            count += pat[start + i];
        }

        cout<<count<<endl;
    }
}
