#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    string st;
    cin >> st;
    for(int i = 0; i < st.length()-1; i++){
        if(st[i] == 'A' && st[i+1] == 'C'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
