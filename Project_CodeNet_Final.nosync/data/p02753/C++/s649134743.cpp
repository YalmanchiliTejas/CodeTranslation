#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int i=0,cnt1=0,cnt2=0;
    while(s[i]) {
    	if(s[i]=='A') cnt1++;
    	else cnt2++;
    	i++;
    }
    if(cnt1&&cnt2) cout << "Yes";
    else cout << "No";
    cout << "\n";
    return 0;
}

