#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define pi 3.14159265358979
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>   vi;
typedef vector<pii>   vpii;
typedef vector<vi>    vvi;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
