//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int h,w;
vector<string> a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h>>w;
    for (int i = 0; i < h; i++)
    {
        string temp;
        cin >> temp;
        a.push_back(temp);
    }
    int count=0;
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                count++;
            }
        }
    }
    int count1=1;
    int i=0;
    int j=0;
    while(true){
        while(true){
            if(i==w-1){
                break;
            }
            if(a[j][i+1]=='#'){
                i++;
                count1++;
            }
            else{
                break;
            }
        }
        if(j==h-1)break;
        if(a[j+1][i]=='#'){j++;count1++;}
        else{
            return cout<<"Impossible"<<"\n",0;
        }
    }
    //cout<<i<<" "<<j<<"\n";
    if(count1==count&&i==w-1&&j==h-1)return cout<<"Possible"<<"\n",0;
    else{
        return cout<<"Impossible"<<"\n",0;
    }
}
