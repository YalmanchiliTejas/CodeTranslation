#include <bits/stdc++.h>
#define int long long
#define INT_MAX INT64_MAX
#define INT_MIN INT64_MIN
#define PI 3.14159265358979323846
#define CLK clock_t clk = clock();//Start of main
#define OCLK cerr << "Time (in ms): " << (double)(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';//End of main
#define MOD 1000000007
/* DEFINE cout */
#define pln cout << "===============================\n"
#define on cout<<"\n"
#define os cout<<" "
#define o2(a,b) cout<<a<<" "<<b
#define o(a) cout << a
#define bitcount __builtin_popcountll
/* DEFINE cout */
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);//fastio
using namespace std;
struct hash_pair { // use pair as key in unordered_map<pair<int,int>,int,hash_pair>;
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
bool prime[10000001];
int P=MOD-2;
int factorial[10000001]={0};
int powerFunction(int x,int y){
    int res = 1;
    int p = MOD;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
void sieveFunction(int maxLimit){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1]=false;
    for(int i=2; maxLimit >= i ; i++){
        if(prime[i]){
            for(int j=2*i ; maxLimit >= j ; j+=i)
                prime[j]=false;
        }
    }
}
void factorialFunction(int maxLimit){
    factorial[0]=1;
    for(int i=1 ; i <= maxLimit ; i++)
        factorial[i]=(factorial[i-1]*i)%MOD;
    return;
}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
signed main(){
    int n;
    cin >> n;
    if(n >= 30){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}




