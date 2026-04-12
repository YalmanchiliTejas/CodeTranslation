#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(n) int n; scanf("%d",&n);
#define mod 10000007
#define N 100001
#define MX 1000000001
#define log(n) (int)log2(n)
#define log(a)(b) log(b)/log(a)
#define pb(x) push_back(x);
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define scArr(n) int n; scanf("%d", &n); int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
#define pi acos(-1)

int main()
{
    string s;
    cin>>s;
    int a=0;
    for(int i=0;i<s.size();i++) if(s[i]=='A') a++;
    if(a==s.size() || a==0) cout<<"No";
    else cout<<"Yes";
}
