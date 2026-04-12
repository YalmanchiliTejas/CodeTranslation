#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

multiset<int> st;

int A[MAXN];
char S[MAXN];

int main()
{
    int n,m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    set<int>::iterator it;

    for(int i=n;i>=1;i--){
        it = st.lower_bound(A[i]+1);
        if(it==st.end()){
            cnt++;
            st.insert(A[i]);
        }
        else {
            st.erase(it);
            st.insert(A[i]);
        }
    }

    cout<<cnt<<"\n";


    return 0;
}
