#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define PI acos(-1)
#define pb push_back
#define int long long
#define ld long double
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int M = (1e9)+7;
const int N = 1e6+5;

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        int n;
        cin>>n;
        cout<<((n>=30)?"Yes":"No")<<endl;
    }
    return 0;
}
