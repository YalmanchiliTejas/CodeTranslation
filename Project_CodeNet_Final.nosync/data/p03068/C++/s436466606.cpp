#include<bits/stdc++.h>
int main()
{
    using namespace std;

    int n,k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    for(int i=0;i<n;i++){
        if(s[i] != s[k-1]){
            cout << "*";
            continue;
        }
        cout << s[i];
    }
    cout << "\n";

    return 0;
}