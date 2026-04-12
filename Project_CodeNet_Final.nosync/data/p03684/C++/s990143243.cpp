#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define All(v) v.begin(),v.end()
using namespace std;
int n;
int id[200000];
void initialize()
{
    for(int i=0;i<200000 ; i++)
        id[i] = i;
}

int root (int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1 (int x, int y)
{
    int p = root(x) , q = root(y);
    id[p] = id[q];
}

int main()
{
    initialize();
    vector < pair < int , ii > > v;
    vector < pair < ii , int > > v2 , v3;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v2.push_back(mp(mp(x,y) , i));
        v3.push_back(mp(mp(y,x) , i));
    }
    sort(v2.begin() , v2.end());
    sort(v3.begin() , v3.end());
    for(int i=1;i<n;i++)
    {
        pair < ii , int > X1 = v2[i];
        pair < ii , int > X2 = v2[i-1];
        int cost = abs(X2.fr.fr-X1.fr.fr);
        v.push_back(mp(cost , mp(X1.sc , X2.sc)));

        X1 = v3[i];
        X2 = v3[i-1];
        cost = abs(X2.fr.fr-X1.fr.fr);
        v.push_back(mp(cost , mp(X1.sc , X2.sc)));

    }
    sort(v.begin() , v.end());
    ll ans = 0;
    for(int i=0;i<v.size();i++)
    {
        int cost = v[i].fr;
        ii node = v[i].sc;
        if(root(node.fr)!= root(node.sc))
        {
         union1(node.fr,node.sc);
         ans+=cost;
        }
    }
    cout<<ans;
}
