#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double long dl;
typedef pair < int , int > pii;
typedef pair < pii, pii > p2i;
const int maxn = (int) 3e5 + 1;
const int mod = (int) 1e9 + 7;
const ll inf = (ll)1e18;

#define fi first
#define se second
#define acel ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define next continue

int n;
int a[maxn];
vector < int > v;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++){
        if(v[n / 2 - 1] >= a[i]){
            cout << v[n / 2] << "\n";
        }
        else {
            cout << v[n / 2 - 1] << "\n";
        }
    }
}
