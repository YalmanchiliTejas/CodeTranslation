#include <bits/stdc++.h>
#define dbgi(x) cout << #x << " = " << (x) << "\n";
#define dbgvi(x) cout << #x << " = "; for(int i = 0; i < (x.size()); ++i) cout << x[i] << " ";
#define mrk() cout << "HERE\n"
#define vi vector < int >
#define vs vector < string >
#define vii vector < vi >
#define viii vector < vii >
#define viiii vector < viii >
#define pii pair < int, int >
#define vpii vector < pii >
#define foru(i, a, b) for(int i = a; i < b; ++i)
#define ford(i, b, a) for(int i = b; i > a; --i)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld long double
using namespace std;

signed main(){
    int n;
    cin >> n;
    vi a(n + 1);
    foru(i, 1, n + 1)cin >> a[i];
    vi odd;
    vi even;
    foru(i, 1, n + 1){
        if(i % 2){
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }
    if(n % 2 == 0){
        reverse(even.begin(), even.end());
        foru(i, 0, even.size()){
            cout << even[i] << " ";
        }
        foru(i, 0, odd.size()){
            cout << odd[i] << " ";
        }
    } else {
        reverse(odd.begin(), odd.end());
        foru(i, 0, odd.size()){
            cout << odd[i] << " ";
        }
        foru(i, 0, even.size()){
            cout << even[i] << " ";
        }
    }
}
