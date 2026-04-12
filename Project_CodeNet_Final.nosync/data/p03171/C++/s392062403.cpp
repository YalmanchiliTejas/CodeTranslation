#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;

const int MAXN = 3005;

ll diff[MAXN][MAXN]={0};
ll A[MAXN];
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> A[i];

    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            diff[i][j] = max(A[i]-diff[i+1][j], A[j]-diff[i][j-1]);
        }
    }

    cout << diff[0][n-1] << '\n';

    return 0;
}

