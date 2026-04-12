#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ll n;
    cin >> n;
    string s;
    map<char,ll> alpha;
    ll i,j,k;
    for(i=0;i<26;i++){
        alpha[(char)('a'+i)]=100;
    }
    ll cnt;
    for(i=0;i<n;i++){
        cin >> s;
        for(j=0;j<26;j++){
            cnt=0;
            for(k=0;k<s.size();k++){
                if(s[k]==(char)('a'+j))cnt++;
            }
             alpha[(char)('a'+j)]=min(alpha[(char)('a'+j)],cnt);
        }
    }
    for(i=0;i<26;i++){
        for(j=0;j<alpha[(char)('a'+i)];j++){
            cout <<(char)('a'+i);
        }
    }
    return 0;
}
