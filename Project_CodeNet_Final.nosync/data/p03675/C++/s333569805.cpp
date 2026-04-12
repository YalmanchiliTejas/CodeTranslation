#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long int ll;
typedef vector< pair<int, int> > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;

int n, arr[nax], arr1[nax];
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
      int cur = 1;
    int r = (n / 2) + 1;
    int l = (n / 2);
    if(n % 2 == 1)
        arr1[r] = arr[cur], cur++, r++;

    while(r <= n)
    {
        arr1[r] = arr[cur];
        cur++;
        arr1[l] = arr[cur];
        cur++;
        r++, l--;
    }
    for(int i = 1; i <= n; i++)
        cout << arr1[i] << " ";
    return 0;
}
