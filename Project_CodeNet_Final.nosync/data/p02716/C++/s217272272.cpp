#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#pragma optimize("fast-math")

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define endl '\n'
#define ull unsigned long long
#define si short int
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define piii pair<pair<int, int>, int>
#define all(vec) (vec).begin(), (vec).end()
#define piiii pair<pair<int, int>, pair<int, int>>

vector<ll> dp_nech;
vector<ll> dp_ch;
vector<ll> prefodd;
void solve() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    dp_nech.resize(n);
    dp_ch.resize(n);
    prefodd.resize(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        if(i%2==0){
            prefodd[i]=arr[i];
        }
        prefodd[i]+=(i-1>=0)?prefodd[i-1]:0;
    }
    for (int i = 0; i <n ; ++i) {
       if(i%2==1){//i+1 - kolvo-chetnoe
           dp_ch[i]=max(arr[i]+((i-2>=0)?dp_ch[i-2]:0), prefodd[i]);
       }
       else{
           dp_nech[i]=max(arr[i]+((i-2>=0)?dp_nech[i-2]:0), (i-1>=0)?dp_ch[i-1]:0);
       }
    }
    if(n%2==0){
        cout<<dp_ch[n-1];
    }
    else{
        cout<<dp_nech[n-1];
    }

}

void testcases(int n) {
    n = 1 - n;
    if (!n) cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "r", stdin);
    //f=fopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "w");
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "w", stdout);

    unsigned int beg_time = clock();
    testcases(0);
    // 0 - no t, 1 - with t

    unsigned int end_time = clock();
    //cout << endl << endl << end_time - beg_time;
    return 0;
}