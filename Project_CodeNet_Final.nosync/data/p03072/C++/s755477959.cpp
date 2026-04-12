    #include <bits/stdc++.h>
    #define fio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define ll long long int
    #define ld long double
    #define f(a, b) for (ll i = a; i < b; i++)
    #define in(a, b) (b.find(a) != string::npos)
    #define X first
    #define Y second
    #define vi vector<int>
    #define fill(a, x) memset(a, x, sizeof(a))
    #define pb push_back
    #define pf push_front
    #define mp make_pair
    #define all(v) v.begin(), v.end()
    #define el "\n"
    const ll M = 1e9 + 7;
    using namespace std;

    int main() {
    fio;
    int n;cin>>n;
    int a[n]={0};
    int b[n]={0};
    for(int i=0;i<n;i++)cin>>a[i];
    b[0]=a[0];
    for(int i=1;i<n;i++)b[i]=max(b[i-1],a[i]);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(b[i]==a[i])cnt++;
    }
    cout<<cnt<<el;
    return 0;
    }
