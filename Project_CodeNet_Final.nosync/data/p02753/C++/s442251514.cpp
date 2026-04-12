//dhruv
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ffor(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define ff first
#define ss second


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s;
    cin >> s;
    bool a = false,b = false;
    ffor(i,s.length()){
        if(s[i] == 'A')a = true;
        else if(s[i] == 'B')b = true;
    }    
    if(a&b){
        cout << "Yes";
    }else{
        cout << "No";
    }
}		