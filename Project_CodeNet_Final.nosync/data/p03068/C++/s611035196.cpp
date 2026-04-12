#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    string str;

    cin >> n;
    cin >> str;
    cin >> k;

    str = str;

    for(int i = 0; i < n; i++){
        if(str[i] != str[k - 1]){
            str[i] = '*';
        }
    }

    cout << str << endl;

    return 0;
}

