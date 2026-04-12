#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    for(i = 0; i < (int) str.size() - 1; i++)
    if(str[i] == 'A' && str[i + 1] == 'C') {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}
