#include<bits/stdc++.h>
#include<vector>
#define inf 1000000
#define ll unsigned long long 
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int main(){
    string str; cin >> str;
    int n = str.size();
    unordered_map<char, int> mp;

    for(int i =0; i<n; i++)
        mp[str[i]]++;
    
    if(mp['A'] < 1 || mp['B'] < 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}


