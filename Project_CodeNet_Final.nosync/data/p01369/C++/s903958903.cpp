#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<set>
#include<stack>
#include<complex>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
#define bv vector<bool>
using namespace std;
typedef pair<int, int>PA;
using namespace std;
#define MAX  999999
int main(){
    string comp = "yuiophjklnm";
    while(true){
        string s; bool check = false; bool belong = true;
        cin >>s; if(s.size() == 1 && s[0] == '#') break;
        int ans = 0;
        // y u i o p h j k l n m
        rep(i,s.size()){
            if(i == 0)rep(k,11){if(s[i] == comp[k]) check=true;}
            belong = false;
            rep(k, 11)if(s[i] == comp[k]){belong = true;}
            if(belong)if(check == false){ans++;check = true;}
            if(!belong)if(check == true){ans++;check = false;}
        }
        cout << ans << endl;
    }
}