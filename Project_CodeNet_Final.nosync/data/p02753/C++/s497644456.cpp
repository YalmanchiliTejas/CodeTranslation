#include<bits/stdc++.h>

#define bb      begin()
#define ee      end()
#define ff      first
#define ss      second
#define pb      push_back
#define pf      push_front
#define popb    pop_back()
#define popf    pop_front()
#define mem(a , v)    memset(a , v , sizeof(a))

typedef long long ll;
typedef long double ld;

using namespace std;

const int BIG = 1e5+9;
const int INF = 1e9+9;
const ll BINF = 1e18+9;
const double SML = (1e-7);

string a;

int main()
{
    //freopen("output.txt" , "w" , stdout);
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    if(a!="AAA" && a!="BBB")
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
