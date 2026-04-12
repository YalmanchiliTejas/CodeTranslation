#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;

    vector<int> a(26,INF);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int b[26] = {};
        for(int j = 0; j < s.length(); j++){
            b[s[j]-'a']++;
        } 
        for(int j = 0; j < 26; j++){
            if(b[j] != 0) a[j] = min(a[j],b[j]);
            else a[j] = 0;
        }
    }

    for(int i = 0; i < 26; i++){
        if(a[i] != INF){
            for(int j = 0; j < a[i]; j++){
                cout << char('a'+i);
            }
        }
    }
    cout << endl;

    return 0;
}