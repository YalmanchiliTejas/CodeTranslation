#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD 1000000007
#define pb push_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll M;
ll X;

ll ltmp;
string stmp;
double dtmp;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
map<ll,ll> count_map;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> X;
    cin >> M;

    ll ai = X;
    ll ni = 0;
    while(ni<N){
        count_map[ai]++;
        ni++;
        
        ai = ai * ai;
        ai = (ai + M ) % M;
        if(ai==0){
            ni = N;
            break;
        }
        else if(count_map[ai]>0){
            map<ll,ll> roop_val;
            ll am = ai;
            ll roop_cnt = 0;
            while(roop_val[am] == 0){
                roop_val[am]++;
                roop_cnt++;
                am = am * am;
                am = (am + M) %M;
            }

            ll leftN = N - ni;
            ll roopi = leftN/roop_cnt;
            //cout << "roop " << roop_cnt << " " << roopi << endl;
            for(auto x : roop_val) {
                ll val = x.first;
                count_map[val] += count_map[val] * roopi;
            }
            ni += roopi * roop_cnt;
            break;
        }
    }
    while(ni<N){
        count_map[ai]++;
        ni++;
        
        ai = ai * ai;
        ai = (ai + M ) % M;
    }

    ll ans = 0;
    for(auto x : count_map) {
        ll val = x.first;
        ll num = x.second;
        //cout << val << " " << num << endl;
        ans += val * num;
    }
    cout << ans << endl;
    

}