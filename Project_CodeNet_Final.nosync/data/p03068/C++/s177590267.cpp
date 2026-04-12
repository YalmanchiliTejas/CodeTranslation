#include <bits/stdc++.h>

using namespace std;
using namespace std;
typedef long long ll;
#define endl "\n";
#define MAX 10000001+9   //Maximum array size;
#define loop(n) for(ll i=0;i<n;i++)
#define loop2(n) for(ll i=0;i<n;i+=2)
#define all(v) v.begin(),v.end()
#define sz(v)  v.size()
typedef vector<ll> vi;
typedef set<ll> si;

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}

int pow(int a, int b) {
    int pow = 1;
    loop(b)pow *= a;
    return pow;
    //thanks m7md :)
}

int main() {
    fast();
  //freopen("input.txt","r",stdin);
    int n;cin>>n;
    string s;cin>>s;
    int k;cin>>k;
    for (int i = 0; i <n ; ++i) {
        if(s[i]!=s[k-1])s[i]='*';
    }
    cout<<s;

}

