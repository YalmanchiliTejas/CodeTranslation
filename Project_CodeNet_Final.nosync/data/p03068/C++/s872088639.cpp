#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){
    int n, k;
    string s;
    cin >> n;
    cin >> s >> k;
    char c = s[k-1];
    for (int i = 0; i < n; i++)
    {
        if(c==s[i]){
            cout << s[i];
        }
        else cout <<'*';
    }
    cout << endl;
    
}