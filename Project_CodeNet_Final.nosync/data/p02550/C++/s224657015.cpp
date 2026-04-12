#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int tc;

int main()
{
    FIO
    ll n, x, m;
    cin>>n>>x>>m;
    map<ll, int> mp;
    vector<ll> vec;
    ll prev = x;
    ll sum = 0;
    int i = 0;
    for(i = 0 ; i < n ; i++)
    {
        
        if(prev == 0)
            break;
        if(mp.count(prev))
            break;
        mp[prev]++;
        vec.push_back(prev);
        prev = (prev * prev) % m;
        // cout<<"num "<<prev<<endl;
    }
    for(auto x : vec)
        sum += x;
    if(i == n || prev == 0)
    {   
        cout<<sum;
        return 0;
    }
    int idx = find(vec.begin(), vec.end(), prev) - vec.begin();
    // cout<<"idx: "<<idx<<endl;
    ll rem = n - (int) vec.size();
    // cout<<"rem: "<<rem<<endl;
    ll csum = 0;
    for(int j = idx; j < (int) vec.size() ; j++)
        csum += vec[j];
    // cout<<vec.size()<<endl;
    int cyclesize = (int) vec.size() - idx;
    // cout<<"cycleSzie: "<<cyclesize<<endl;
    // cout<<"Csum: "<<csum<<endl;
    sum += csum *(rem / cyclesize);
    for(int j = idx; j < idx + (rem%cyclesize) ; j++)
        sum += vec[j];
    cout<<sum<<endl; 

    return 0;
}