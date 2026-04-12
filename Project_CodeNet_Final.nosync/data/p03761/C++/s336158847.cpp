#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n;
string s;
int a[] = {};
map<char,int> mp,tmp;
int main(){
    cin >> n;
    cin >> s; //入力
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    //入力2
    for(int i = 1; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[s[j]]++;
        }
        for(char c = 'a'; c <= 'z'; c++){
            mp[c] = min(mp[c], a[c]);
        }
        for(char c = 'a'; c <= 'z'; c++){
            a[c] = 0; //初期化
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        while(mp[c]){
            cout << c;
            mp[c]--;
        }
    }
    cout << endl;
}

