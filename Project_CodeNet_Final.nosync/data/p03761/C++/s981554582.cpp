#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define INF 210000000
#define int long long

int gcd(int a, int b) {
  int amari = a % b;
  int c = b;
  if (amari == 0) {
    return b;
  } else {
    return gcd(b, amari);
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

signed main() {
    int n;
    cin >> n;
    vector<string> s;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    set<char> st;
    map<char,int> cnt1;
    map<char,int> cnt2;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            st.insert(s[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        cnt2.clear();
        for(int j=0;j<s[i].length();j++){
            if(i == 0) cnt1[s[i][j]]++;
            cnt2[s[i][j]]++;
            st.insert(s[i][j]);
        }
        for(auto& a : st){
            if(cnt2[a] < cnt1[a]) cnt1[a] = cnt2[a];
            else cnt2[a] = cnt1[a];
        }
    }
    for(auto& a : cnt1){
        for(int i=0;i<a.second;i++){
            cout << a.first;
        }
    }
}

