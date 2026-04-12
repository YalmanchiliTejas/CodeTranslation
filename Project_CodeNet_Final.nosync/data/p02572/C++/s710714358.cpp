#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define PII pair<int,int>
#define INF LONG_MAX
#define ull unsigned long long
#define long long long
#define PIL pair<long,int>
#define M 1000000007
#define endl "\n"

void fastIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

}

int main()
{
	fastIO();
    int n;
    cin>>n;
    long ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    long prefix[n]={0};
    prefix[0] = ar[0];
    for(int i =1;i<n;i++){
        prefix[i]  = (prefix[i-1]+ar[i])%M;
    }
    long ans = 0;
    int k = n-1;
    for(int i=0;i<n;i++){
        long store = prefix[n-1]-prefix[i];
        ans = (ans+(ar[i]*store)%M+M)%M;
    }
    cout<<ans;
    return 0;
}

