#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define INF 0x3f3f3f3f
#define maxn 10
using namespace std;
typedef long long LL;
typedef pair <int,int> PP;
int n,r;
double a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n){
        deque <int> dq;
        for(int i=1,a;i<=n;i++){
            cin >> a;
            if(i&1) dq.push_front(a);
            else dq.push_back(a);
        }
        if(n&1){
            for(int i=0;i<dq.size();i++) cout << dq[i] << " ";
            cout << endl;
        }
        else{
            for(int i=dq.size()-1;i>=0;i--) cout << dq[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
