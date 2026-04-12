#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
string u="abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    string s[N];
    int check[N][26];
    memset(check,0,sizeof(check));
    for(int i=0;i<N;i++){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        const char *cstr=s[i].c_str();
        for(int j=0;j<s[i].length();j++){
            check[i][(int)cstr[j]-(int)'a']++;
        }
    }
    for(int i=0;i<26;i++){
        int mini=100;
        for(int j=0;j<N;j++){
            mini=min(mini,check[j][i]);
        }
        for(int j=0;j<mini;j++) cout << u[i];
    }
    cout << "\n";
    return 0;
}