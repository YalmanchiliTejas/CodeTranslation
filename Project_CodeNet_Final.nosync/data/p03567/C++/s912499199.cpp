#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define mem(a,b) memset(a,b,sizeof(a))
#define shutdown ios::sync_with_stdio(false)
#define MAX 10e18+1000
#define INF 0x3f3f3f3f
#define FOR(x,k) for(int x=1;x<=k;x++)



int main()
{
    shutdown;
    string a;
    cin>>a;
    int l=a.length();
    for(int i=0;i<l-1;i++){
        if(a[i]=='A'&&a[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
