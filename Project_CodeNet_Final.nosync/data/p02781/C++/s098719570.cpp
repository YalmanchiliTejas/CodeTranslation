#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define first_more_idx(ve, num) upper_bound(all(ve), num)-ve.begin() // idx = first_more_idx(ve,num); if(idx = ve.size()) , then not exist
#define first_lessequal_idx(ve, num) lower_bound(all(ve), num)-ve.begin()
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > // only sort first param
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll power(ll x, ll n){if(n == 0) return 1;return  (n%2)? x*power(x, n-1)%MOD : power(x*x%MOD, n/2);}
ll dx[]={0, 0, -1, 1};
ll dy[]={1, -1, 0, 0};// up,down,left right

ll cal1(string N){
    if(N == "0" or N.size() == 0) return 0;
    ll ans = 9LL * (N.size()-1) + (N[0] - '0');
    return ans;
}

// N = [a][b]*****
ll cal2(string N){
    ll ans = 0LL;
    if(N.size() < 2) return ans;
    
    // 1桁: 1~(a-1)なら
    // それ以外(N.size() -1)の桁に、1~9までの数字なんでも
    ans += (N[0] - '1') * 9LL * (N.size() - 1);
    

    
    // 1桁: [a]なら
    string Ntmp = "";
    rep(i, N.size()){
        if(i == 0) continue;
        if(N[i] == '0') continue;
        else{
            Ntmp =  N.substr(i);
            break;
        }
    }
    ans += cal1(Ntmp);
    
    //ans += (N[1] - '0') + 9LL * (N.size() - 2);
    
    
    // N.size() - 1桁までの全ての2桁も入る
    if(N.size() > 2){
        ll tmp = (N.size() - 1LL) * (N.size() - 2LL);
        tmp /= 2LL;
        tmp *= (9LL*9LL);
        ans += tmp;
    }


    return ans;
}

// N = [a][b][c]***
ll cal3(string N){
    ll ans = 0LL;
    if(N.size() < 3) return ans;
    
    // 1桁: 1~(a-1)なら
    //                     残りの桁から2桁選ぶ
    //                                                           それぞれ
    ans += (N[0] - '1') * ((N.size()-1LL)*(N.size()-2LL)/2LL) * 81;
    
    // 1桁: [a]なら
    string Ntmp = "";
    rep(i, N.size()){
        if(i == 0) continue;
        if(N[i] == '0') continue;
        else{
            Ntmp =  N.substr(i);
            break;
        }
    }
    ans += cal2(Ntmp);
    
    
    
    // N.size() -1桁までの全ての3桁も入る
    if(N.size() > 3){
        ll tmp = (N.size() - 1LL) * (N.size() - 2LL) * (N.size() - 3LL);
        tmp /= 6LL;
        tmp *= (9LL*9LL*9LL);
        ans += tmp;
    }
    
    return ans;
    
}

pair<string, ll> R(ll keta){
    
    string str = "";
    ll num = 0;
    
    while(str.size() < keta){
        ll n = rand() % 9;
        if(str == "" and n == 0){
            continue;
        }
        str += ('0' + n);
        num *= 10;
        num += n;
    }
    
    return mp(str, num);
}

void stress(){
    ll KETA = 3;
    cerr << "begin" << endl << flush;
    
    while(true){
        pair<string, ll> rd = R(5);
        ll ans1 = cal3(rd.first);

        
        ll ans2 = 0;
        rep(i, rd.second + 1){

            ll num = i;
            ll keta = 0;
            
            while(num != 0){
                if((num % 10) != 0) keta ++;
                num /= 10;
            }
            
            if(keta == KETA) ans2 ++;
        }
        
        cout << "----------" << rd.first << "-----" << endl ;
        cout << ans1 <<  "::[" << ans2 << "]" << endl << flush;
        
        if(ans1 != ans2){
            return ;
        }
        
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    
     //stress();
    
    string N;
    cin >> N ;

    ll K; cin >> K;
    
    
    if(K == 1) cout << cal1(N) << endl;
    if(K == 2) cout << cal2(N) << endl;
    if(K == 3) cout << cal3(N) << endl;

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
