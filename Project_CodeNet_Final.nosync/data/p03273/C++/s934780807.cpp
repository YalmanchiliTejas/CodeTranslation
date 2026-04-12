#include<bits/stdc++.h>
using namespace std;
char s[105][105];
bool ignoreR[105];
bool ignoreC[105];
 
int main() {
    int n, m;
	
    cin>>n>>m;
    for(int i = 0; i < n; i++) {cin>>s[i];}
	
    for(int i = 0; i < n; i++) {
        ignoreR[i] = true;
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') ignoreR[i] = false;
        }
    }
    for(int j = 0; j < m; j++) {
        ignoreC[j] = true;
        for(int i = 0; i < n; i++) {
            if(s[i][j] == '#') ignoreC[j] = false;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ignoreR[i] || ignoreC[j]) continue;
            cout<<s[i][j];
        }
        cout<<"\n";
    }
    return 0;
}