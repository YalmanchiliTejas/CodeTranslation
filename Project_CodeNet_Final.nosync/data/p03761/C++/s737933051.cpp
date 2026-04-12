#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 55
#define INF 1000000009

int n;
string s[MAXN];
map<char, int> mp[MAXN];

int mn(int a, int b){
    return a < b ? a : b;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < (int)s[i].size(); j++){
            mp[i][s[i][j]]++;
            mp[52][s[i][j]] = INF;
            if(mp[51][s[i][j]] == i){
                mp[51][s[i][j]] = i + 1;
            }
        }
    }
    map<char, int> :: iterator ite;
    for(int i = 0; i < n; i++){
        for(ite = mp[i].begin(); ite != mp[i].end(); ++ite){
            mp[52][ite->first] = mn(mp[52][ite->first], ite->second);
            //printf("mp[52][%c] = %d\n", ite->first, mp[52][ite->first]);
        }
    }
    for(ite = mp[52].begin(); ite != mp[52].end(); ++ite){
        if(ite->second > 0 && mp[51][ite->first] == n){
            for(int i = 0; i < ite->second; i++){
                printf("%c", ite->first);
            }
        }
    }

    printf("\n");



    return 0;
}
