#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<random>
#include<bitset>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++) //0から
#define REP(i,n) for(int j=i;j<n;j++) //iから
#define in(a) cin>>a
#define out(a) cout<<a<<endl
typedef long long ll;


struct SegmentTree{
    private:
        int n;
        vector<int> node;

    public:
        SegmentTree(vector<int> v){
            int z = v.size();
            n = 1;
            while(n < z) n *= 2;//一番下の段
            node.resize(2 * n - 1, 0);

            for(int i=0; i < z; i++) node[(n - 1) + i] = v[i];//一番下の段

            for(int i=n-2;i >= 0; i--){
                node[i] = compare(node[i * 2 + 1], node[i * 2 + 2]);
            } 
        }

        int compare(int a, int b){
            return (a | b);
        }

        void update(int i, int val){
            i += n - 1;
            node[i] = val;

            while(i > 0){
                i = (i - 1) / 2;
                node[i] = compare(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        int find(int a, int b, int now = 0, int l = 0, int r = -1){
            if(r < 0) r = n;
            //cout<<a<<' '<<b<<"   ";
            //cout<<now<<' '<<l<<' '<<r<<endl;
            if(r <= a || b < l) return 0;//単位元的な

            //if((a <= l && r <= b + 1) || 2 * (now+1) >= 2*n - 1 ) return node[now];
            if(a <= l && r <= b + 1) return node[now];

            int vl = find(a, b, 2 * now + 1, l, (l + r) / 2);
            int vr = find(a, b, 2 * now + 2, (l + r) / 2, r);

            return compare(vl, vr);
        }

        int number(int m){
            int tmp = 0;
            while(m>0){
                if(m%2==1) tmp++;
                m/=2;
            }
            return tmp;
        }
};


ll kaijo(ll n){
    if(n == 0) return 1;
    return n * kaijo(n-1);
}

ll POW(ll x, ll n){
    ll ans = 1;
    while(n > 0){
        if(n & 1 == 1){
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }

    return ans;
}

ll combination(ll a, ll b){
    ll tmp;
    tmp = kaijo(a) / (kaijo(b) * kaijo(a-b));
    return tmp;
}

vector<bool> is_prime;
void Eratosthenes(ll n){
    is_prime.resize(n+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(ll i = 2; i <= n; i++){
        if(is_prime[i]){
            for(ll j = i*i; j <= n; j++){
                is_prime[j] = false;
            }
        }
    }
}

//素数列挙
vector<ll> Prime;
void Prime_Enumeration(ll n){
    Eratosthenes(n);
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            Prime.push_back(i);
        }
    }
}

ll gcd(ll a, ll b){
    if(a<b){
        swap(a,b);
    }
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return r;
}

ll lcm(ll a, ll b){
    ll g = gcd(a,b);
    ll l = (a * b) / g;

    return l;
}

//aが負の時でも余りを非負にしたいとき
ll  mod(ll a, ll m){
    return (a % m + m) % m;
}

//拡張ユークリッド ap + bq = gcd(a,b)
ll extGCD(ll a, ll b, ll &p, ll &q){
    if(b == 0){ p = 1; q = 0; return a;}
    ll d = extGCD(b, a % b, q, p);
    q -= a /b * p;
    
    return d;
}

//中国剰余定理
pair<ll, ll> ChineseRem(ll b1, ll m1, ll b2, ll m2){
    ll p, q;
    ll d = extGCD(m1, m2, p, q);

    if((b2-b1) % d != 0) return make_pair(0, -1); //解なし

    ll m = m1 * (m2 / d);
    ll tmp = (b2 - b1) / d * p % (m2 / d);
    ll r =mod(b1 + m1 * tmp, m);

    return make_pair(r, m);
}

//mod.mでのa^{-1}
ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a /b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if(u < 0)u += m;
    return u;

}
const ll MOD = 1000000007;

//key以上のうち最小の要素のindex
int binary_search(ll *a, ll n, ll key){
    ll right = n, left = -1;
    ll md = (right + left) / 2;

    while(right - left > 1){
        if(a[md] <= key){
            right = md;
        }else{
            left = md;
        }
        md = (right + left) / 2;
    }
    if(left == -1) return -1; //無い場合
    return right;
}

//英字ならture、数字ならfalse
bool isalpha(char s){
    if(('A'<=s&&s<='Z')||('a'<=s&&s<='z')){
        return 1;
    }else{
        return 0;
    }
}
//全ての文字が英字ならture、数字ならfalse
bool Isalpha(string s){
    ll n;
    bool tmp = true;
    rep(i,n){
        if(isalpha(s[i])){
            tmp = false;
        }
    }
    return tmp;
}

string YES(bool a){
    return a ? "YES" : "NO";
}

string Yes(bool a){
    return a ? "Yes" : "No";
}

void f(ll n, vector<ll> v){
    for(int i=1;i<=n;i++){
        v[i]=0;
        for(int h=n;h>=1;h--){
            v[i] += h - i + 1;
        }
    }
}


using Graph = vector<vector<ll>>;


int main(){
    ll h,w;
    cin>>h>>w;
    char a[10][10];
    string ans = "Possible";
    rep(i,h){
        rep(k,w){
            cin>>a[i][k];
        }
    }
    rep(i,h-1){
        rep(j,w-1){
            if(a[i][j]=='#'){
                if(a[i+1][j]=='#'&&a[i][j+1]=='#'){
                    ans = "Impossible";
                }
            }
        }
    }
    REP(1,h){
        rep(i,w){
            if(i==0) continue;
            if(a[j][i]=='#'){
                if(a[j-1][i]=='#'&&a[j][i-1]=='#'){
                    ans = "Impossible";
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}