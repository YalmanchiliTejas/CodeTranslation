/*---------------Go Code GO---------------*/

#include<bits/stdc++.h>
using namespace std;

#define     PI              acos(-1.0)
#define     O_O             ios_base::sync_with_stdio(false); cin.tie(NULL)
#define     precision(a)    fixed<<setprecision(a)
#define     endl            '\n'
#define     Flush           cout<<flush
#define     LLMX            0x3fffffffffffffff
#define     PW2(a)          (long long)1<<a


vector<long long> vc;
multimap<long long, int> mp;
int main()
{
    long long i,j,k,l,m,n,o,p,q,r,tst,ans=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>k;
        vc.push_back(k);
    }
    for(i=0; i<n; i++)
    {
        auto it=mp.lower_bound(vc[i]-1);
        if(it==mp.end())
        {
            if(mp.size()) { it--; mp.erase(it); }
            mp.insert({vc[i],i});

        }
        else if(it->first==vc[i]-1)
        {
            mp.erase(it);
            mp.insert({vc[i],i});
        }
        else if(it==mp.begin())
            mp.insert({vc[i],i});
        else
        {
            it--;
            mp.erase(it);
            mp.insert({vc[i],i});
        }

//        for(auto K: mp)
//        cout<<K.first<<'-'<<K.second<<' ';
//        cout<<endl;
    }


    cout<<mp.size()<<endl;
    return 0;
}

//5, 2, 6, 4, 3
