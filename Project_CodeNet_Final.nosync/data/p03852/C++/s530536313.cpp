#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vector<int, int> > vvi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;
int main(){
    char a;
    cin >> a;
    if(a=='a' || a=='e' || a=='i' || a=='u' || a=='o'){
        cout << "vowel";
    }
    else cout << "consonant";
}