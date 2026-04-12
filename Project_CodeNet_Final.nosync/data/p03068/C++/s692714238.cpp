#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;


int main(){
    int n;cin >> n;
    string s;cin >> s;
    int k;cin >> k;
    for (int i = 0; i < s.length(); i++) {
        cout << (s[i]==s[k-1]?s[i]:'*');
    }
    cout << "\n";
    return 0;
}

