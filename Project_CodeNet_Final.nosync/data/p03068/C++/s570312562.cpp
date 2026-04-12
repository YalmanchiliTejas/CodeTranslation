#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
int n, k;
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>s>>k;
    s=s.c_str();
    char kc=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=kc){
            s[i]='*';
        }
    }
    for(int i=0;i<n;i++){
        cout <<s[i];
    }
    cout<<"\n";
}