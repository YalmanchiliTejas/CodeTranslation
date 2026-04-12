#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define N 1e5+1;
#define INF 1e9

const ll MOD = 10e9+7;
ll max(ll a, ll b){return a > b ? a : b;}
ll min(ll a, ll b){return a < b ? a : b;}

vector<int> ans;
ll a[200001];
ll b[200001];
vector<int> sorted;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string str;
    cin >> n >> str >> k;
    for(int i=0; i<n; i++)
    {
        if(str[i]!=str[k-1]) str[i] = '*';
    }
    cout << str;
}



