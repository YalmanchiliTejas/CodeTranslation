#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int mod = 998244353;
const ll inf = 3e18 + 5;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }  

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < 3; i++)
        if(s[i] == 'A')
            cnt++;
    if(cnt > 0 && cnt < 3)
        cout << "Yes";
    else
        cout << "No";   
}