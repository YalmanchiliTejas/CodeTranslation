#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;
const ll inf = 3e18 + 5;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }  
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int suma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        suma = add(suma, a[i]);
    }
    int sol = 0;
    for(int i = n - 1; i > 0; i--){
        suma = sub(suma, a[i]);
        sol = add(sol, mul(a[i], suma));
    }
    cout << sol % mod;
}

