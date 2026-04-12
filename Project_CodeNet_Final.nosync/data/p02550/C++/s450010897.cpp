//i hate _____
#include<bits/stdc++.h>

#define ll long long int 
#define ld long double 
#define pb push_back
#define mk make_pair
#define ii pair<int , int>

using namespace std;
double pi = 2 * acos(0.0) ;
const int M=1e5;

template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << " " << x;
        return os << '}'; 
}

vector<int>v(M+1);
map<ll,int>mp;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,x,m; cin>>n>>x>>m;
    ll ans = 0;
    int move ;
    for (move=1;move <= n ; move++){
        //x %= m;
        mp[x]++;
        if (mp[x]==2) break;
        ans += x;
        v[x] = move ;
        x *= x; x %= m;
    }
    if (move > n) {
        cout << ans << endl;
        return 0;
    }
    //cout << move << endl;
    ll majhe = move - v[x] ; //cout << majhe << endl;
    ll baki = n-move+1;
    vector<int>sum; sum.pb(0);
    ll ss=0;
    for (int i=0;i<majhe;i++){
        //x %= m;
        //mp[x]++;
        //if (mp[x]==2) break;
        ss += x; sum.pb(ss);
        //v[x] = move ;
        x *= x; x %= m;
    }
    ans += (ss*(baki/majhe));
    ans+= sum[baki%majhe];
    cout << ans << endl;
    
    return 0;
}
/*
    problems are the sign of life
*/
