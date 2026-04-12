#include<bits/stdc++.h>

using namespace std;

int white[200005], black[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; string s;

    cin >> n >> s >> k; k--;

    char temp = s[k];
    for(auto &i : s) if(i != temp) i = '*';
    cout << s;

    return 0;
}
