#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

string ar[50];
void solve() {
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    int mp[50][26] = {0};
    char ch;
    for(int i=0;i<n;i++) {
        for(int j=0;j<ar[i].size();j++) {
            mp[i][ar[i][j] - 'a']++;
        }
    }
    string s;
    for(int i=0;i<26;i++) {
        int m = 50;
        for(int j=0;j<n;j++) {
            m = min(mp[j][i], m);
        }
        cout<<endl;
        for(int j=0;j<m;j++) {
            s += (char)(i+'a');
        }
    }
    cout<<s<<endl;
}

int main() {
    solve();
    return 0;
}