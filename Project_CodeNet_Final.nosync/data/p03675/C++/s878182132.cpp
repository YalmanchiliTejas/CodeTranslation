// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull  unsigned long long
typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int INF = 1e9 + 5;
const int N = 2e5 + 123;
int main(){
    speed;
    int n;
    cin >> n;
    vi a, b;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(i & 1){
            a.pb(x);
        }
        else{
            b.pb(x);
        }
    }
    if(n & 1){
        reverse(all(b));
        for(int i = 0; i < b.size(); ++i){
            cout << b[i] << " ";
        }
        for(int i = 0; i < a.size(); ++i){
            cout << a[i] << " ";
        }
    }
    else{
        reverse(all(a));
        for(int i = 0; i < a.size(); ++i){
            cout << a[i] << " ";
        }
        for(int i = 0; i < b.size(); ++i){
            cout << b[i] << " ";
        }
    }
}