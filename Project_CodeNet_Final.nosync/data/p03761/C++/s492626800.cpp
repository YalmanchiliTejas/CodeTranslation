#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793
int dx[] = {0,1,-1,0,1,-1,1,-1};
int dy[] = {1,0,0,-1,1,-1,-1,1};

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    map<char, int> m;
    for(auto s: v){
        map<char, int> m2;
        for(auto c: s){
            m2[c]++;
        }
        for(auto p: m2){
            if(m[p.first] == 0 || m[p.first] > p.second)
                m[p.first] = p.second;
        }
    }
    for(auto s: v){
        for(auto p: m){
            if(s.find(p.first) == string::npos)
                m[p.first] = 0;
        }
    }
    string ans = "";
    for(auto p: m){
        for(int i = 0; i < p.second; i++)
            ans += p.first;
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
}
