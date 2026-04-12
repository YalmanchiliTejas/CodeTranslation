#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int main(){
        string N;
        cin >> N;
        bool flagA = false;
        bool flagB = false;
        for(char x :N) {
                if(x == 'A') flagA = true;
                else flagB = true;
        }
        if(flagA && flagB) cout << "Yes" << endl;
        else cout << "No" << endl;
}
