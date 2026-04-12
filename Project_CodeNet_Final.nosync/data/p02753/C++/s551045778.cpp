#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;

#define pb push_back
#define ff first
#define ss second
#define SIZE 2001
#define INF 2e9 + 9
#define acmpIN "input.txt"
#define acmpOUT "output.txt"
#define usacoIN "buckets.in"
#define usacoOUT "buckets.out"

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


int n, h, l, r, a[SIZE];

ll ans[200001];


int kol[2];
string s;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen(acmpIN, "r", stdin);
//    freopen(acmpOUT, "w", stdout);

    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        kol[s[i] - 'A']++;
    }

    if(kol[0] && kol[1])
        cout << "Yes";
    else cout << "No";


    return 0;
}
