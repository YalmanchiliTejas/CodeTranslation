#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define OUT(x) cout << (x) << endl
typedef long long ll;
typedef vector<int> V;
typedef vector<vector<int>> VV;
typedef pair<int, int> P;
typedef map<string, int> M;
typedef unordered_map<int, int> HM;
typedef set<int> S;
typedef multiset<int> MS;
typedef queue<int> Q;

int main(){
    int n; cin>>n;
    map<char,int> m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(i == 0){
            for(char c : s)
                m[c]++;
        }
        else{
            map<char, int> temp;
            for(char c : s)
                temp[c]++;
            for(auto p : m){
                if(temp[p.first])
                    m[p.first] = min(p.second, temp[p.first]);
                else
                    m[p.first] = 0;
            }
        }
    }
    string ans = "";
    for(auto p : m){
        for(int i=0; i<p.second; i++)
            ans += p.first;
    }
    OUT(ans);
}