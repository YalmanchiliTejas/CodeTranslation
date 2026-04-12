#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=1000005;
#define M 1000000007
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;



 
#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);


     

    int n, x, m;
    cin >> n >> x >> m;
    int cnt = 1, prev = 0, ans = x, ok = 0, ind = -1;

    vector<int>v(N, 0);
    map<int, int>mapi;

    v[cnt] = x, mapi[x] = cnt;
    while(cnt < n){
        int cur = (x * x) % m;
        //deb(cur)
        if(mapi[cur]){ 
            ind = mapi[cur];
            ok = 1;
            break;
        }
        ans += cur;
        x = cur;
        cnt++;
        //deb(x)
        mapi[x] = cnt;
        v[cnt] = x;
    }

    if(ok){
        int s = 0;
        for(int i = ind; i <= cnt; i++)
            s += v[i];
        int period = cnt - ind + 1, left = n - cnt;
        ans += (left / period) * s;
        for(int i = ind; i < ind + (left % period); i++)
            ans += v[i];

        cout << ans << endl;
    }else{
        cout << ans << endl;
    }



    
return 0;  
}