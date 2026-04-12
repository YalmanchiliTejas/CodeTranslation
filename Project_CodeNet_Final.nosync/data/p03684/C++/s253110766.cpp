#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

vector <int> leader;

int findleader(int a)
{
    if( a == leader[a])
        return a;

    leader[a] = findleader(leader[a]);
    return leader[a];
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int n, u, v, i, j, t1, t2;

    vector <pair <int, pair <int, int>> > storage;
    vector <bool> visited;
    vector <pair <int, int>> xcoords, ycoords;


    cin >> n;
    xcoords.pb(MP(0, 0));
    ycoords.pb(MP(0, 0));
    visited.pb(0);
    leader.pb(0);
    for(i = 1; i <= n; ++i)
    {
        cin >> u >> v;
        xcoords.pb(MP(u, i));
        ycoords.pb(MP(v, i));
        visited.pb(0);
        leader.pb(0);
    }

    sort(xcoords.begin(), xcoords.end());
    sort(ycoords.begin(), ycoords.end());

    for(i = 2; i < xcoords.size(); ++i)
    {
        storage.pb( MP ( xcoords[i].fi-xcoords[i-1].fi, MP(xcoords[i-1].se, xcoords[i].se) ));
        storage.pb( MP ( ycoords[i].fi-ycoords[i-1].fi, MP(ycoords[i-1].se, ycoords[i].se) ));
    }
    sort(storage.begin(), storage.end());

    long long sum =0;
    for(i = 0; i < storage.size(); ++i)
    {

        u = storage[i].se.fi;
        v = storage[i].se.se;
        if( !leader[u])
        {
            if( !leader[v] )
            {
                leader[u] = v;
                leader[v] = v;
            }
            else
            {
                leader[u] = v;
            }
            sum += storage[i].fi;
        }
        else if( !leader[v])
        {
            leader[v] = u;
            sum += storage[i].fi;
        }
        else
        {
            t1 = findleader(u);
            t2 = findleader(v);
            if( t1 != t2)
            {
                leader[t1] = t2;
                sum += storage[i].fi;
            }
        }
    }
    cout << sum ;

}
